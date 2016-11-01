#ifndef SPELL_CHECKER_HPP
#define SPELL_CHECKER_HPP

#include <string>
#include <vector>
#include "pset.h"

class spell_checker {
private:
	const std::string dictionary_filename;
	const std::string text_filename;
	pset<std::string> dictionary;
	std::vector<std::string> text;
	bool check_word(const std::string &word);
	void parse_text();
	void save_text();
	void remove_punctuation_character(std::string &word, std::string &prefix, std::string &suffix);
	void start();
	int check_prefix(const std::string &word);
	int check_suffix(const std::string &word);
public:
	spell_checker(const std::string &dfilename, const std::string &tfilename) 
		: dictionary_filename(dfilename),  text_filename(tfilename),
		  dictionary(dfilename) {
		  	parse_text();
		  	start();
		  	save_text();
	}
};

#endif