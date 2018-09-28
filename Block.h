
#ifndef BLOCK_H
#define BLOCK_H

#include "Point.h"
#include <vector>
using std::vector;

enum class BlockType { Empty, Normal, Special1, Special2, Special3, V_Wall, H_Wall, UL_Edge, UR_Edge, BL_Edge, BR_Edge};

class Block {
public:
	// constructor
	Block(int y = 0, int x = 0);
	// for translating
	void MoveBy(int dx, int dy);
	void Rotate();
	void UnRotate();
	void Randomize();
	// getter
	const Point& getLocation();
	const vector<vector<BlockType> >& getArray();
	bool hasChanged();
	// setter
	void setChanged(bool ok);
	
protected:
	// block array
	vector<vector<BlockType> > _array;
	// rotate except ...
	bool _canRotate;

private:
	// info to provide Tetris.Class
	Point _position;
	bool _hasChanged;
};

#endif /* BLOCK_H */
