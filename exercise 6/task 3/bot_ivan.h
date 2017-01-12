#ifndef _BOT_IVAN_H_
#define _BOT_IVAN_H_

#include <ctime>
#include "player.hpp"

class bot_ivan : virtual public player {
public:

	bot_ivan(){
		isHuman = false; 
		srand(time(NULL));
	}
	~bot_ivan(){ }

	int play(const playfield &field){
		int playerAStones, playerBStones, empty;

		// Check every horizontal possibility
		for (int i = 0; i < playfield::width - 3; ++i){
			for (int j = 0; j < playfield::height; ++j){
				playerAStones = 0;
				playerBStones = 0;
				empty = -1;
				for (int k = 0; k < 4; ++k){
					if (field.stoneat(i+k, j) == 0){
						if (j == playfield::height-1 || field.stoneat(i+k, j+1) != 0) empty = i+k;
					}
					if (field.stoneat(i+k, j) == 1) ++playerAStones;
					if (field.stoneat(i+k, j) == 2) ++playerBStones;
				}
				if (playerAStones == 3 || playerBStones == 3){
					if (empty != -1) return empty;
				}
			}
		}
		
		// Check every vertical possibility
		for (int i = 0; i < playfield::width; ++i){
			for (int j = 0; j < playfield::height - 3; ++j){
				playerAStones = 0;
				playerBStones = 0;
				empty = -1;
				for (int k = 0; k < 4; ++k){
					if (field.stoneat(i, j+k) == 0) empty = i;
					if (field.stoneat(i, j+k) == 1) ++playerAStones;
					if (field.stoneat(i, j+k) == 2) ++playerBStones;
				}
				if (playerAStones == 3 || playerBStones == 3){
					if (empty != -1) return empty;
				}
			}
		}

		// Check every diagonal '/' possibility
		for (int i = 0; i < playfield::width - 3; ++i){
			for (int j = 3; j < playfield::height; ++j){
				playerAStones = 0;
				playerBStones = 0;
				empty = -1;
				for (int k = 0; k < 4; ++k){
					if (field.stoneat(i+k, j-k) == 0){
						if (j-k+1 == playfield::height-1 || field.stoneat(i+k, j-k+1) != 0) empty = i+k;
					}
					if (field.stoneat(i+k, j-k) == 1) ++playerAStones;
					if (field.stoneat(i+k, j-k) == 2) ++playerBStones;
				}
				if (playerAStones == 3 || playerBStones == 3){
					if (empty != -1) return empty;
				}
			}
		}
		// Check every diagonal '\' possibility
		for (int i = 0; i < playfield::width - 3; ++i){
			for (int j = 0; j < playfield::height - 3; ++j){
				playerAStones = 0;
				playerBStones = 0;
				empty = -1;
				for (int k = 0; k < 4; ++k){
					if (field.stoneat(i+k, j+k) == 0){
						if (j+k+1 == playfield::height-1 || field.stoneat(i+k, j+k+1) != 0) empty = i+k;
					}
					if (field.stoneat(i+k, j+k) == 1) ++playerAStones;
					if (field.stoneat(i+k, j+k) == 2) ++playerBStones;
				}
				if (playerAStones == 3 || playerBStones == 3){
					if (empty != -1) return empty;
				}
			}
		}
		return rand() % 7;;
	}

private:
	bool isHuman;
};

#endif