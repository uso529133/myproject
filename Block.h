
#ifndef BLOCK_H
#define BLOCK_H

#include "Point.h"
#include <vector>
using std::vector;

class Block {
public:
	// constructor
	Block(int y = 0, int x = 0);
	// translation functions
	void MoveBy(int dx, int dy);
	void Rotate();
	// location getter
	const Point* getLocation();
	
private:
	// block array
	vector<vector<bool> > _array;
	// block position in TetrisMap
	Point _position;
	// rotate except Square Block
	bool _canRotate;	
};

#endif /* BLOCK_H */
