#ifndef PVECTOR_HPP_
#define PVECTOR_HPP_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

template<typename T>
class pvector {
private:
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
	T operator[] (std::size_t pos) { return v.at(pos); }
	std::size_t size() { return v.size(); }

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
				ifs >> x;
				v.push_back(x);
			}
		}
		ifs.close();
	}

	void write_vector() {
		std::ofstream ofs (filename.c_str(), std::ofstream::trunc);
		typename std::vector<T>::iterator fst = v.begin(), lst = v.end();
		while (fst != lst) {
			ofs << *fst++;
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
