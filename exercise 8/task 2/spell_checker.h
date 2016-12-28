#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include <string>
#include <regex>
#include <fstream>
#include <iostream>
#include <sstream>
#include "pset.h"

class spell_checker {
private:
	const std::string dictionary_filename;
	const std::string text_filename;
	pset<std::string> dictionary;
	std::string get_content(std::string filename);
	void analyse_text();
public:
	spell_checker(std::string df, std::string tf) : dictionary_filename(df), text_filename(tf), dictionary(df) {
		analyse_text();
	}
};

#endif