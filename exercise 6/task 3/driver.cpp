#include "playfield.hpp"
#include "connect4.hpp"
#include "humanplayer.hpp"
#include "computerplayer.hpp"
#include "bot_ivan.h"
#include "player_nico.h"
#include <iostream>

int main(int argc, char const *argv[]) {
	humanplayer p1;
	player_nico p2(2);
	connect4 con(&p1, &p2);
	return 0;
}
