#include "playfield.hpp"
#include "connect4.hpp"
#include "player.hpp"

#include <iostream>

int main(int argc, char const *argv[]) {
	player<playfield> p1(1);
	player<playfield> p2(1);
	connect4<player<playfield>> con(p1, p2);
	return 0;
}
