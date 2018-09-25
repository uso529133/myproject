
#ifndef BLOCK_H
#define BLOCK_H

#include "Point.h"
#include <vector>

using std::vector;

class Block {
public:
	// constructor
	Block(int y = 0, int x = 0);
	// for translating
	void MoveBy(int dx, int dy);
	void Rotate();
	// getter
	const Point& getLocation();
	const vector<vector<bool> >& getArray();
	
protected:
	// block array
	vector<vector<bool> > _array;
	// rotate except ...
	bool _canRotate;	
	
private:
	// Block position in TetrisMap
	Point _position;
};

#endif /* BLOCK_H */
