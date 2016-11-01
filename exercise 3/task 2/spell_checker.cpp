#include "spell_checker.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
/**
 * Checks if the dictionary contains a specific word.
 * @param  word The word from which we want to know if it is in the dictionary
 * @return      True if it is in the dictionary, false otherwise
 */
bool spell_checker::check_word(const std::string &word) {
	auto result = dictionary.find(word);

	if (result != dictionary.end()) {
		return true;
	} else {
		return false;
	}
}

int spell_checker::check_prefix(const std::string &word) {
	int i = 0;
	while (i < int(word.length())) {
		if (ispunct(word.at(i))) {
			i++;
		} else {
			return i;
		}
	}
	return i;
}

int spell_checker::check_suffix(const std::string &word) {
	int i = int(word.length() - 1);
	while (i >= 0) {
		if (ispunct(word.at(i))) {
			i--;
		} else {
			return i;
		}
	}
	return i;
}

void spell_checker::remove_punctuation_character(std::string &word, std::string &prefix, std::string &suffix) {
	int prefix_length = check_prefix(word);
	int suffix_length = (word.length() - 1) - check_suffix(word);

	prefix = word.substr(0, prefix_length);
	suffix = word.substr(word.length() - suffix_length, suffix_length);

	word.erase(0, prefix_length);
	word.erase(word.length() - suffix_length, suffix_length);
}

void spell_checker::save_text() {
	std::ofstream ofs(text_filename + ".corrected");

	for(std::vector<std::string>::const_iterator iter = text.begin(); iter != text.end(); ) {
	    ofs << *iter++ << ' ';
	}
}

void spell_checker::parse_text() {
	std::ifstream ifs(text_filename);
	//check if file is empty
	if (ifs.peek() != std::ifstream::traits_type::eof()) {
		while(true) {
			if(!ifs.good()) { break; }
			std::string word;
			ifs >> word;
			text.push_back(word);
		}
	} else {
		throw std::length_error("Your text file is empty!");
	}

	if (text.size() == 0) {
		throw std::runtime_error("There was a problem reading your file.");
	}

	ifs.close();
}

/**
 * Starts the spell_checker.
 */
void spell_checker::start() {
	char command;
	for (std::string &word : text) {
		//remove all punctiation characters
		std::string prefix = "", suffix = "";
		remove_punctuation_character(word, prefix, suffix);
		if (!check_word(word)) {
			check_word:
				bool valid_command = false;
				while(!valid_command) {
					std::cout << word << std::endl;
					std::cout << "(a)dd,   "
							  << "(i)gnore,    "
							  << "(r)eplace? ";
					std::cin >> command;

					switch (command) {
						case 'a':
							dictionary.insert(word);
							valid_command = true;
							break;
						case 'i':
							valid_command = true;
							break;
						case 'r':
							valid_command = true;
							std::cout << "Please enter the correct version of the word \"" << word << "\": ";
							std::string correction;
							std::cin >> correction;
							word = correction;
							goto check_word;
					}
				}
		}
		word = prefix + word + suffix;
	}
}