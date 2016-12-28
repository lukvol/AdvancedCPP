#include "spell_checker.h"

std::string spell_checker::get_content(std::string filename) {
	//http://stackoverflow.com/a/116083
	std::ifstream ifs(filename);
	std::stringstream sstr;
	while (ifs >> sstr.rdbuf());
	ifs.close();

	return sstr.str();
}

void spell_checker::analyse_text() {
	std::regex word_regex(R"(\w+)");
	std::string content = get_content(text_filename);

	auto regiter_b = std::sregex_iterator(content.begin(), content.end(), word_regex);
    auto regiter_e = std::sregex_iterator();

    while (regiter_b != regiter_e) {
    	std::smatch match = *regiter_b++;
    	std::string result = match.str();

    	auto dict_b = dictionary.begin();
    	auto dict_e = dictionary.end();
    	bool did_match = false;

    	while (dict_b != dict_e) {
    		std::regex check(*dict_b++);
    		if (std::regex_match(result, check)) {
    			did_match = true;
    			break;
    		}
    	}
    	if (!did_match) {
    		std::cout << result << std::endl;
    	}
    }
}