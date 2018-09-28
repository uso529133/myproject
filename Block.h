
#ifndef BLOCK_H
#define BLOCK_H

#include "Point.h"
#include <vector>
using std::vector;

enum BlockType { Empty, Normal, V_Wall, H_Wall, UL_Edge, UR_Edge, BL_Edge, BR_Edge, Special_A, Special_B, Special_C };

class Block {
public:
	// constructor
	Block(int y = 0, int x = 0);
	// for translating
	void MoveBy(int dx, int dy);
	void Rotate();
	void UnRotate();
	// getter
	const Point& getLocation();
	vector<vector<int> >& getArray();
	bool hasChanged();
	// setter
	void setChanged(bool ok);
	
protected:
	// block array
	vector<vector<int> > _array;
	// rotate except ...
	bool _canRotate;

private:
	// info to provide Tetris.Class
	Point _position;
	bool _hasChanged;
};

#endif /* BLOCK_H */
