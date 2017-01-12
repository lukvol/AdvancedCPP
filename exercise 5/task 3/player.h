#ifndef PLAYER_H_
#define PLAYER_H_

#include "playfield.hpp"
#include <cstdlib>
#include <iostream>

template<typename F>
class player {

public:
	/**
	 * @mode player mode. 0 = computer, 1 = manual
	 * @nr number of the player.
	 */
	player(int mode, int nr) {
		player_mode = mode;
		player_nr = nr;
		std::cout << "Player Nr: " << player_nr << std::endl;
		winning_col = -1;
	}

	int play(const F &field) {
		if (player_mode == 0) {
			int tmp = is_winnable(field, player_nr);
			if (tmp != -1) {
				std::cout << "Win" << std::endl;
				return tmp;
			}
			tmp = is_winnable(field, (player_nr == 1 ? 2 : 1));
			if (tmp != -1) {
				std::cout << "Blocked" << std::endl;
				return tmp;
			} else {
				std::cout << "Random" << std::endl;
				return select_row(field);
			}
		} else {
			int col;
			do{
				std::cout << "Player " << player_nr << " please enter a column:" << std::endl;
				std::cin >> col;
			}while(col>=field.width || col<0);
			return col;
		}
	}

	void set_player_mode(int mode){
		player_mode = mode;
	}

private:
	int player_nr;
	int winning_col;
	int player_mode;

	/**
	 * Returns an int between 0 and max-1
	 */
	int random(int max) {
		return std::rand() % max;
	}

	/**
	 * If the game can be won, returns the winning column, else -1
	 */
	int is_winnable(const F &field, int player) {

		int tmp;

		for (int i = 0; i < field.width; i++) {
			for (int j = 0; j < field.height; j++) {
				winning_col = -1;
				tmp = is_winnable_recursive(i, j, 1, 0, 0, field, 3, player);
				if (tmp != -1) {
					return tmp;
				}
				winning_col = -1;
				tmp = is_winnable_recursive(i, j, 0, 1, 0, field, 3, player);
				if (tmp != -1) {
					return tmp;
				}
				winning_col = -1;
				tmp = is_winnable_recursive(i, j, 1, 1, 0, field, 3, player);
				if (tmp != -1) {
					return tmp;
				}
				winning_col = -1;
				tmp = is_winnable_recursive(i, j, -1, 1, 0, field, 3, player);
				if (tmp != -1) {
					return tmp;
				}
			}
		}

		return -1;
	}

	int is_winnable_recursive(int x, int y, int x_dir, int y_dir, int step,
			const F &field, int missing, int player) {

		if (step == 3 && missing == 1) {
			//return the winning column
			return winning_col;
		}

		if (between(x + x_dir, 0, field.width)
				&& between(y + y_dir, 0, field.height)) {

			if (step == 2 && missing == 1) {
				if (field.stoneat(x + x_dir, y + y_dir) == 0
						&& ((field.stoneat(x + x_dir, (y + y_dir) + 1) != 0)
								|| (y + y_dir + 1) == field.height)) {
					return x + x_dir;
				}
			}

			//if the current slot could be occupied
			if (field.stoneat(x, y) == 0
					&& ((field.stoneat(x, y + 1) != 0)
							|| (y + 1 == field.height))
					&& field.stoneat(x + x_dir, y + y_dir) == player) {
				winning_col = x;
				return is_winnable_recursive(x + x_dir, y + y_dir, x_dir, y_dir,
						++step, field, missing, player);
			}

			//if the current slot is occupied
			if (field.stoneat(x + x_dir, y + y_dir) == field.stoneat(x, y)
					&& field.stoneat(x, y) == player) {
				return is_winnable_recursive(x + x_dir, y + y_dir, x_dir, y_dir,
						++step, field, --missing, player);
			}

			//first slot occupied, then space, then occupied again
			if (field.stoneat(x, y) == player
					&& field.stoneat(x + 2 * x_dir, y + 2 * y_dir) == player
					&& field.stoneat(x + x_dir, y + y_dir) == 0
					&& ((field.stoneat(x + x_dir, y + y_dir + 1) != 0)
							|| (y + y_dir + 1 == field.height))
					&& between(x + 2 * x_dir, 0, field.width)
					&& between(y + 2 * y_dir, 0, field.height) && step < 2) {
				return is_winnable_recursive(x + x_dir, y + y_dir, x_dir, y_dir,
						++step, field, --missing, player);
			}
		}

		return -1;
	}

	/**
	 * Selects a random row to place the stone
	 */
	int select_row(const F &field) {
		return random(field.width);
	}

	/**
	 * returns true if min <= x < max
	 */
	bool between(int x, int min, int max) {
		return (x >= min) && (x < max);
	}
};

#endif /* PLAYER_H_ */