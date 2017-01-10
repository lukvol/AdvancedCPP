#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include <iostream>
#include <random>

#include "player.hpp"

/**
 * Class player, which is used to play the game as player or against a bot.
 */

class humanplayer : public player {
private:
public:
	/**
	 * Initiates the player. if the player is a bot, it will get a 0,
	 * if it is a human interacting with the app, its 1
	 * @param field field of game played now
	 */
	humanplayer() {
	}
	// returns the column where the player decides to throw in his 
	// stone
  	virtual int play(const playfield &field);
};

#endif /* HUMANPLAYER_HPP */
