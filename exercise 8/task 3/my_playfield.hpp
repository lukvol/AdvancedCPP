#ifndef MY_PLAYFIELD_HPP
#define MY_PLAYFIELD_HPP


#include <iostream>
#include "playfield.hpp"

class my_playfield : public playfield {
public:

protected:
	//the internal representation of the field
	char rep[my_playfield::width][my_playfield::height];
	int height_for_row(int x);

public:
	//return the stone (none/player1/player2) at the position (x,y)
	//0 <= x < width
	//0 <= y < height
	//stoneat(0,0) .................. top left
	//stoneat(width-1, height-1) .... bottom right
	//if we insert a stone in a new column i,
	//it lands at (i, height - 1)
	my_playfield(){}
	int stoneat(int x, int y) const { return rep[x][y]; }
	void show_field();
	bool place_stone_at(int x, int player);
	bool is_full();
	void clear_array();
};

#endif
