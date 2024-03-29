#ifndef MYMIN_H
#define MYMIN_H

#include <cstring>

template<typename T>

inline T mymin(T a, T b) {
	return a<b ? a : b;
}
template<> inline
char *mymin<char *>( char *a, char *b) {
	return strcmp(a,b)<0 ? a : b;
}
template<> inline
const char *mymin<const char *>(const char *a, const char *b) {
	return strcmp(a,b)<0 ? a : b;
}

#endif
