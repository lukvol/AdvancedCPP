#ifndef PERSISTENCE_TRAITS_H
#define PERSISTENCE_TRAITS_H

#include <string>
#include <fstream>

template<typename T>
struct persistence_traits {
	static void read(std::ifstream &i, T &elem) { i >> elem; }
	static void write(std::ofstream &o, const T &elem) { o << elem; }
};

template<>
struct persistence_traits<std::string> {
	static void read(std::ifstream &i, std::string &elem) { std::getline(i, elem); }
	static void write(std::ofstream &o, const std::string &elem) { o << elem; }
};


#endif
