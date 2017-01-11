#include "playfield.hpp"
#include "connect4.hpp"
#include "player.hpp"

#include <iostream>

int main(int argc, char const *argv[]) {
	player *p1 = playerFactory::make("N(1)");
	player *p2 = playerFactory::make("T");
	connect4 con(p1, p2);
	return 0;
}
