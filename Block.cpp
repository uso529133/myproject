
#include "Block.h"
#include "stdlib.h"

Block::Block(const char* p, bool canRotate)
 : _position({0, 0}), _canRotate(canRotate), _array(5, vector<BlockType>(5, BlockType::Normal)), _hasChanged(true) 
{
	for (int i = 0; i < _array.size(); ++i) {
		for (int j = 0; j < _array.size(); ++j) {
			_array[i][j] = BlockType::Normal;
			
			if (*p == '1') {
				switch (rand() % 4) {
					case 0:
						_array[i][j] = BlockType::Normal;
						break;
					case 1:
						_array[i][j] = BlockType::Special1;
						break;
					case 2:
						_array[i][j] = BlockType::Special2;
						break;	
					case 3:
						_array[i][j] = BlockType::Special3;
						break;
				}
			} else _array[i][j] = BlockType::Empty;
			
			p++;
		}
	}
}

void Block::MoveBy(int dy, int dx) {
	_position.x += dx;
	_position.y += dy;
	
	setChanged(true);
}

void Block::Rotate() {
	if (!_canRotate) return;
	auto tempArray(_array);
	
	for (int i = 0; i < _array.size(); ++i) {
		for (int j = 0; j < _array.size(); ++j) {
			_array[i][j] = tempArray[_array.size() - 1 - j][i];
		}
	}
	setChanged(true);
}

void Block::UnRotate() {
	if (!_canRotate) return;
	auto tempArray(_array);
	
	for (int i = 0; i < _array.size(); ++i) {
		for (int j = 0; j < _array.size(); ++j) {
			_array[i][j] = tempArray[j][_array.size() - 1 - i];
		}
	}
	setChanged(true);
}

const Point& Block::getLocation() { return _position; }

const vector<vector<BlockType> >& Block::getArray() { return _array; }

void Block::setChanged(bool ok) { _hasChanged = ok; }

bool Block::hasChanged() { return _hasChanged; }

