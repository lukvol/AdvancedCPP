#ifndef PLAYFIELD_HPP
#define PLAYFIELD_HPP

class playfield {
public:
	//The size of the playfield
	const static int width = 7;
	const static int height = 6;

	//these elements are used to indicate whether a given position
	//in the playing field is taken by a given player
	const static int none = 0;
	const static int player1 = 1;
	const static int player2 = 2;

protected:
	//the internal representation of the field
	char rep[playfield::width][playfield::height];
	int height_for_row(int x);

public:
	//return the stone (none/player1/player2) at the position (x,y)
	//0 <= x < width
	//0 <= y < height
	//stoneat(0,0) .................. top left
	//stoneat(width-1, height-1) .... bottom right
	//if we insert a stone in a new column i,
	//it lands at (i, height - 1)
	int stoneat(int x, int y) const { return rep[x][y]; }
	void show_field();
	bool place_stone_at(int x, int player);
	bool is_full();
	void clear_array();
};

#endif
