
#include "Block.h"

Block::Block(int y, int x) : _position({x, y}), _canRotate(true), _array(5, vector<bool>(5, true)), _hasChanged(true) {}

void Block::MoveBy(int dy, int dx) {
	_position.x += dx;
	_position.y += dy;
	
	setChanged();
}

void Block::Rotate() {
	if (!_canRotate) return;
	auto tempArray(_array);
	
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			_array[i][j] = tempArray[4 - j][i];
		}
	}
	setChanged();
}

const Point& Block::getLocation() {
	return _position;
}

const vector<vector<bool> >& Block::getArray() {
	return _array;
}

void Block::setChanged() { _hasChanged = true; }

bool Block::hasChanged() { return _hasChanged; }

