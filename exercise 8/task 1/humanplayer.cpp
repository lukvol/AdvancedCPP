#include "humanplayer.hpp"

/**
 * call the human player to play
 * @param field field of game played now
 * @return token the next row to set the stone in.
 */
static playerFH<humanplayer> registerPlayer;

int humanplayer::play(const playfield &field) {
	//Bot checks 2 possibilites and a fallback: can the bot win, can the player win
	//fallback: random number generation.

		int token;
		std::cout << "Please enter the column where you want to place your token: ";
		std::cin >> token;
		while(std::cin.fail()) {
	        std::cout << "Your input was not valid. Please enter a valid number: " << std::endl;
	        std::cin.clear();
	        std::cin >> token;
	    }

	    while(!(token>=0&&token<=playfield::height)){
	    	std::cout << "Your input was not valid. Please enter a valid number: " << std::endl;
	        std::cin.clear();
	        std::cin >> token;
	    }


		return token;
}

player *humanplayer::make(const char *plr){
	if(plr[0] != 'H') return NULL;
	return new humanplayer();
}