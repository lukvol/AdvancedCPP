#ifndef COMPUTERPLAYER_HPP
#define COMPUTERPLAYER_HPP

#include <iostream>
#include <random>
#include <thread>
#include "player.hpp"

/**
 * Class player, which is used to play the game as player or against a bot.
 */

class computerplayer : public player{
private:
	int can_win(int player, const playfield &field);
	int recursive_can_win(int player, int x, int y, int x_dir, int y_dir, const playfield &field);
	int height_for_row(int x, const playfield &field);
	int get_player_nr(const playfield &field);
	void empty_mid(const playfield &field, int begin, int end);
	bool first_run=false;
	int right;
	int mid;
	int left;
	std::thread *t1;
	std::thread *t2;
	std::thread *t3;
	std::default_random_engine generator;
	std::uniform_int_distribution<> distribution;
public:
	/**
	 * Initiates the player. if the player is a bot, it will get a 0,
	 * if it is a human interacting with the app, its 1
	 * @param field field of game played now
	 */
	computerplayer(){
		generator = std::default_random_engine(time(0));
     	distribution = std::uniform_int_distribution<>(0, 7);
	}
	// returns the column where the player decides to throw in his 
	// stone
  	virtual int play(const playfield &field);
};
#endif
