#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include "playfield.hpp"


class player {
public:
virtual int play(const playfield &field) = 0;
 virtual ~player() {}
};
#endif /* PLAYER_H_ */