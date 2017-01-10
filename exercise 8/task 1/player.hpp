#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include <list>
#include "playfield.hpp"

//creating player inteface
class player {
public:
	//public constructor of player, virtual because needed as interface
	virtual int play(const playfield &field) = 0;
	//public destuctor
	virtual ~player() {}
	static player *make(const char*);
};



typedef player* makeType(const char *);

class playerFactory { 
	static std::list<makeType*> cl;
public:
	static void add(makeType *m) { 
		cl.push_back(m); 
	} 
	static player *make(const char *playr) {
		player *s=NULL; std::list<makeType*>::const_iterator b=cl.begin(), e=cl.end();
		while (b!=e && (s=(*b)(playr))==NULL)++b; 
		return s; 
	} 
};


template<class T> 
struct playerFH { 
	playerFH(makeType *m=(makeType*)&T::make) {
		playerFactory::add(m);
	} 
};

#endif /* PLAYER_H_ */