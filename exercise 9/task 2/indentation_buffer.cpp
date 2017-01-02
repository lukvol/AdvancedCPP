#include "indentation_buffer.h"

void indentation_buffer::reformat(int_type ch) {
	//the goal for a function f() { ... }
	//is to be displayed as following
	//
	//					f() {
	//    					...
	//					}
	//
	//Therefore, the indentation for the } delimiter must be adapted before indenting the line
	//whereas the indentation for the { must be adapted afterwards. 
	if (ch == decrease_delimiter) {
		indentation_level = std::max(0, indentation_level - 1);
		//if the closing delimiter isn't on a new line, we need to insert a newline character
		if (!is_newline) {
			basebuf->sputc('\n');
			is_newline = true;
		}
		//this is used to ensure that the next char printed to the buffer is a newline character
		newline_expected = true;
	}

	if (is_newline) {
		for (int i = 0; i < indentation * indentation_level; ++i) {
			basebuf->sputc(' ');
		}
		is_newline = false;
	}

	if (ch == increase_delimiter) {
		++indentation_level;
		newline_expected = true;
	}
}

indentation_buffer::int_type indentation_buffer::overflow(int_type ch) {
	if (ch != traits_type::eof() && *os && sync() == 0) {
		//if the char currently read is a \n, we do not need to insert one
		if (ch == '\n') {
			if (indentation_level > 0 && is_newline) {
				return ch;
			}
			newline_expected = false;
			is_newline = true;
		}

		//if a newline char is expected but ch != '\n', we need to insert one
		if (newline_expected) {
			basebuf->sputc('\n');
			newline_expected = false;
			is_newline = true;
		}

		//if we are on a new line and encounter space chars as the first characters,
		//we skip them
		if (is_newline && ch == ' ') {
			return ch;
		}

		//if the chars are inside a string, nothing needs to be done
		if (string_delimiter == 0) {
			reformat(ch);

			//check if a string is about to be passed
			if (ch == '\'' || ch == '"') {
				string_delimiter = ch;
			}
		//check if the string is closed
		} else if (ch == string_delimiter) {
			string_delimiter = 0;
		} 

		basebuf->sputc(ch);

		if (ch == '\n') {
			is_newline = true;
		}

		return ch;
	}
	return traits_type::eof();
}