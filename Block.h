
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
	void UnRotate();
	// getter
	const Point& getLocation();
	const vector<vector<bool> >& getArray();
	bool hasChanged();
	// setter
	void setChanged(bool ok);
	// display configuration
	void setFps(int fps);
	
protected:
	// block array
	vector<vector<bool> > _array;
	// rotate except ...
	bool _canRotate;

private:
	// Block position in TetrisMap
	Point _position;
	bool _hasChanged;
};

#endif /* BLOCK_H */
