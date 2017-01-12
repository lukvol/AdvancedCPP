#ifndef CONNECT4_HPP
#define CONNECT4_HPP

#include "my_playfield.hpp"
#include "player.hpp"
#include <iostream>


class connect4 {
private:
	//player from a player class
	int current_player_token = 1;
	player* player1;
	player* player2;
	//bool to check if game is over, used for the main loop
	bool is_finished = false;
	//holding the player field
	my_playfield field;
	bool hasWon(int player);
	bool recursiveHasWon(int player, int x, int y, int x_dir, int y_dir, int step);
	int check_game_state(int player);
	void play_turn();
	void change_player();
public:
/**
 * Initiates a new game with 2 given player
 * @param player 1 player from a player class
 * @param player 2 player from a player class
 */
	connect4(player *player1, player *player2) : player1(player1), player2(player2) {
		start_game(); 
	}
	void start_game();
};

/**
 * Completes setup of the field and starts main loop
 */
void connect4::start_game() {
	field = my_playfield();
	field.clear_array();
	field.show_field();
	while(!is_finished) {
		play_turn();
	}
}

/**
 * Function is called everytime a player is on his turn
 */
void connect4::play_turn() {
	int column;
	do { 
		if (current_player_token == 1) {
			column = player1->play(field);
		} else {
			column = player2->play(field);
		}
	}
	while (!field.place_stone_at(column, current_player_token));
	field.show_field();
	check_game_state(current_player_token);
	current_player_token = current_player_token == 1 ? 2 : 1;
}

/**
 * Function checks if game is won by a player or if the board is full
 * @param player number of the player
 * @return int of what happend 0 nothing special, -1 board is full, 1 if the last player won
 */
int connect4::check_game_state(int player) {
	if (hasWon(player)) {
		is_finished = true;
		std::cout << "Player " << player << " has won. Congratulations!" << std::endl;
		return 1;
	} else if (field.is_full()) {
		is_finished = true;
		std::cout << "Noone wins this time..." << std::endl;
		return -1;
	} else {
		return 0;
	}
}

/**
 * Function will checks if the game is won by recusivly calling recusiveHasWon()
 * @param player number of the player
 * @return bool if the game is won with the last token
 */
bool connect4::hasWon(int player) {
	for (int i = 0; i < playfield::width; i++) {
		for (int j = 0; j < playfield::height; j++) {
			if (field.stoneat(i, j)-48 == player) {
				if (recursiveHasWon(player, i, j, 1, 1, 1) ||
					recursiveHasWon(player, i, j, 1, 0, 1) ||
					recursiveHasWon(player, i, j, -1, 1, 1) ||
					recursiveHasWon(player, i, j, 0, 1, 1)) {
					return true;
				}
			}
		}
	}
	return false;
}

/**
 * recusive function to check is 4 token align
 * @param player number of the player
 * @param player number of the token of the player
 * @param x x-postion on the field from the last call
 * @param y y-postion on the field from the last call
 * @param x_dir direction which the algorithm should take to check next.
 * @param y_dir direction which the algorithm should take to check next.
 * @param step variables which saves the recursive steps
 * @return bool if the game is won with the last token
 */
bool connect4::recursiveHasWon(int player, int x, int y, int x_dir, int y_dir, int step) {
	if (x + x_dir < playfield::width && y + y_dir < playfield::height &&
			x + x_dir >= 0 && y + y_dir >= 0) {
		if (field.stoneat(x + x_dir, y + y_dir)-48 == player) {
			step++;
			if (step == 4) {
				return true;
			} else {
				return recursiveHasWon(player, x + x_dir, y + y_dir, x_dir, y_dir, step);
			}
		}
	}
	return false;
}

#endif
