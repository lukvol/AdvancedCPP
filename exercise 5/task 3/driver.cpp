#include "playfield.hpp"
#include "connect4.hpp"
#include "player_cpu.hpp"
#include "player.h"

#include <iostream>

int main(int argc, char const *argv[]) {
	player<playfield> p1(0,1);
	player_cpu<playfield> p2;
	connect4<player<playfield>, player_cpu<playfield>> con(p1, p2);
	return 0;
}
