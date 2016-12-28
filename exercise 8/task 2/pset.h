#ifndef PSET_H
#define PSET_H

#include <string>
#include <set>
#include <fstream>
#include <iostream>
#include "persistence_traits.h"

template<typename T, typename P=persistence_traits<T>>
class pset {
private:
	std::string filename;
	std::set<T> se;
	bool is_input_empty(std::ifstream& pFile) {
	    return pFile.peek() == std::ifstream::traits_type::eof();
	}
public:
	typedef P persister;
	typedef typename std::set<T>::iterator iterator;
	pset(std::string s): filename(s){ read_set(); }
	~pset() { write_set(); }

	void print_set() {
		for(auto iter = se.begin(); iter != se.end(); ++iter) {
			std::cout << *iter << std::endl;
		}
	}

	void read_set(){
		std::ifstream ifs(filename);
		if(!is_input_empty(ifs)){
		while(true) {
			if(!ifs.good()) { break; }
			T x;
			persister::read(ifs,x);
			se.insert(x);
			}
		}
	}

	void write_set(){
		std::ofstream ofs(filename);
		iterator fst = se.begin(), lst = se.end();
		while(fst != lst){
			persister::write(ofs,*fst++);
			if(fst != lst){
				ofs << std::endl;
			}
		}
		ofs.close();
	}

	iterator find(const T &elem){ return se.find(elem); }
	void insert(const T &elem){ se.insert(elem); }
	void erase(int i){ se.erase(i); }
	void erase(const T &elem){ se.erase(elem); }
	iterator end() { return se.end(); }
	iterator begin() { return se.begin(); }
};

#endif
