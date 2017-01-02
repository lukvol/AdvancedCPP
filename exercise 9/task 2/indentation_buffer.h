#ifndef INDENTATION_BUFFER_H
#define INDENTATION_BUFFER_H

#include <streambuf>
#include <ostream>
#include <string>
#include <iostream>
#include <algorithm>

class indentation_buffer: public std::streambuf {
public:
	std::ostream *os;
	std::streambuf *basebuf;
	int indentation, indentation_level;
	char increase_delimiter = '{', decrease_delimiter = '}';

	bool newline_expected = false;
	bool is_newline = true;
	bool is_string = false;
	char string_delimiter = 0;

	virtual int_type overflow(int_type ch);

	void reformat(int_type ch);
public:
	indentation_buffer(std::ostream &os, int i = 4): os(&os), basebuf(os.rdbuf(this)), indentation_level(0) {
		indentation = i;
	}
	virtual ~indentation_buffer() { 
		if (os != NULL) { os->rdbuf(basebuf); }
	}
};

#endif