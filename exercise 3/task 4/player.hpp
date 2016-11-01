#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

template<typename F>
class player {
private:
	int mode;
	int calculate_row();
public:
	player(int player_mode = 0) : mode(player_mode) {}
	// returns the column where the player decides to throw in his 
	// stone
  	int play(const F &field);
};

template<typename F>
int player<F>::play(const F &field) {
	if (mode == 0) {
		return calculate_row();
	} else {
		int token;
		std::cout << "Please enter the column where you want to place your token: ";
		std::cin >> token;
		while(std::cin.fail()) {
	        std::cout << "Your input was not valid. Please enter a valid number: " << std::endl;
	        std::cin.clear();
	        std::cin >> token;
	    }
		return token;
	}
}

template<typename F>
int player<F>::calculate_row() { return 0; }

#endif