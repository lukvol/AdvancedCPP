#include "playfield.hpp"

#include <iostream>

/**
 * Function will return the y position of the next empty spot in the given row.
 * @param x row x of the field.
 * @param field the field on which the game runs.
 * @return height of the next position
 */
int playfield::height_for_row(int x) {
	int height = playfield::height-1;
	int token = rep[x][height]-48;
	while (token != playfield::none && height >= 0) {
		height -= 1;
		token = rep[x][height]-48;
	}
	return height;
}

/**
 * Prints the game board.
 */
void playfield::show_field() {
	for (int i = 0; i < playfield::height; i++) {
		//draw the current field values
		for (int j = 0; j <= 2 * playfield::width; j++) {
			if (j % 2 == 0) {
				std::cout << "|";
			} else {
				if (rep[j / 2][i]-48 == playfield::none) {
					std::cout << " ";
				} else {
					std::cout << rep[j / 2][i];
				}
			}
 		}
 		std::cout << std::endl;
 		//draw the grid for a row
		for (int j = 0; j <= 2 * playfield::width; j++) {
			if (j % 2 == 0) {
				std::cout << "+";
			} else {
				std::cout << "-";
			}
		}
		std::cout << std::endl;
	}
}
/**
 * Tries to set a stone in a given row and checks if possible
 * @param x row x to place the stone.
 * @param player number of the player
 * @return bool if there is a place in the row, it will return true, if row full false
 */
bool playfield::place_stone_at(int x, int player) {
	int height_to_place = height_for_row(x);
	if (height_to_place < 0) {
		std::cout << "Column is full!" << std::endl;
		return false;
	} else {
		std::string pl = std::to_string(player);
		rep[x][height_to_place] = pl.at(0);
		return true;
	}
}

/**
 * Sets all value to 0 on the board
 */
void playfield::clear_array(){
	for(int i=0; i<playfield::width;i++){
		for(int j=0;j<playfield::height;j++){
			rep[i][j]='0';
		}
	}
}

/**
 * Checks if the board is alreay full
 * @return bool if there is a full board (true) or if there is space(false)
 */
bool playfield::is_full() {
	for (int i = 0; i < playfield::width; i++) {
		if (rep[i][0]-48 == 0) {
			return false;
		}
	}
	return true;
}



