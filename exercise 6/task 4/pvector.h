#ifndef PVECTOR_HPP_
#define PVECTOR_HPP_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "persistence_traits.h"

template<typename T, typename P = persistence_traits<T>>
class pvector {
private:
	typedef P persister;
	typedef typename std::vector<T>::iterator iterator;
	
	std::string filename;
	std::vector<T> v;

	bool is_input_empty(std::ifstream& pFile) {
	    return pFile.peek() == std::ifstream::traits_type::eof();
	}
public:
	pvector(std::string fname) : filename(fname) { read_vector(); }
	~pvector() { write_vector(); }

	void push_back(const T &el) { v.push_back(el); }
	void pop_back() { v.pop_back(); }
	T back() { return v.back(); }
	T operator[] (std::size_t pos) { return v.at(pos); }
	T at(int i){ return v.at(i); }
	std::size_t size() { return v.size(); }
	iterator begin() { return v.begin(); }
	iterator end() { return v.end(); }

	void print_vector(){
		typename std::vector<T>::iterator fst = v.begin(), lst = v.end();
		while(fst != lst) {
			std::cout << *fst++ << std::endl;
		}
	}

	void read_vector() {
		std::ifstream ifs(filename);
		if(!is_input_empty(ifs)) {
			while(true) {
				if(!ifs.good()) { break; }
				T x; 
				persister::read(ifs, x);
				//BUG? if input is std::complex, then the input stream pointer doesn't advance
				//however, if peek() is called afterwards, it works fine.
				ifs.peek();
				v.push_back(x);
			}
		}
		ifs.close();
	}

	void write_vector() {
		std::ofstream ofs (filename.c_str(), std::ofstream::trunc);
		typename std::vector<T>::iterator fst = v.begin(), lst = v.end();
		while (fst != lst) {
			persister::write(ofs, *fst++);
			//Since we advanced the fst iterator, we can check if we have
			//any element left. If we do, we print a new line.
			if (fst != lst) { 
				ofs << std::endl; 
			}
		}
		ofs.close();
	}
};

#endif /* PVECTOR_HPP_ */
