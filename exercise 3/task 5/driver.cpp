#include "playfield.hpp"
#include "connect4.hpp"
#include "player.hpp"

#include <iostream>

int main(int argc, char const *argv[]) {
	player<playfield> p1(0);
	player<playfield> p2(0);
	connect4<player<playfield>, player<playfield>> con(p1, p2);
	return 0;
}
