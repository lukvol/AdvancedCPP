#include "playfield.hpp"
#include "connect4.hpp"
#include "humanplayer.hpp"
#include "computerplayer.hpp"

#include <iostream>

int main(int argc, char const *argv[]) {
	humanplayer p1;
	computerplayer p2;
	connect4 con(&p1, &p2);
	return 0;
}
