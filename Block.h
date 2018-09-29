
#ifndef BLOCK_H
#define BLOCK_H

#include "Point.h"
#include <vector>
using std::vector;

enum class BlockType { Empty, Normal, Special1, Special2, Special3};

class Block {
public:
	// constructor
	Block(const char* p = 0, bool canRotate = true);
	// for translating
	void MoveBy(int dx, int dy);
	void Rotate();
	void UnRotate();
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
