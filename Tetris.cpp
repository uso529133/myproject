
#include "Tetris.h"
#include <iostream>
#include <windows.h>
using namespace std;

enum BlockType { Empty = 0, v_Wall, h_Wall, Edge, Normal};

Tetris::Tetris(int width, int height) 
 : _width(width), _height(height), _map(height, vector<int>(width, BlockType::Empty)) { BuildWalls();
 
 for (int i = 1; i < _width - 2; ++i) _map[_height - 3][i] = BlockType::Normal;
 for (int i = 1; i < _width - 2; ++i) _map[_height - 2][i] = BlockType::Normal;
 for (int i = 1; i < _width - 2; ++i) _map[_height - 4][i] = BlockType::Normal;
  }

void Tetris::BuildWalls() {
 	for (int i = 0; i < _width; ++i) {
 		// top wall
 		_map[0][i] = BlockType::v_Wall;
 		// bottom wall
 		_map[_height - 1][i] = BlockType::v_Wall;
	 }
	for (int i = 0; i < _height; ++i) {
		// left wall
 		_map[i][0] = BlockType::h_Wall;
 		// right wall
 		_map[i][_width - 1] = BlockType::h_Wall;
	 }
	 _map[0][0] = _map[0][_width - 1] = _map[_height - 1][0] 
	 	= _map[_height - 1][_width - 1] = BlockType::Edge;
}



bool Tetris::isDuplicateWith(Block* block) {
	const int& posY = block->getLocation().y;
	const int& posX = block->getLocation().x;

	const vector<vector<bool> >& array = block->getArray();

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (posY + i >= 0 && posX + j >= 0 && posY + i < _height && posX + j < _width 
			&& _map[posY + i][posX + j] != BlockType::Empty && array[i][j] ) { return true; }
		}
	}
	
	return false;
}

void Tetris::ApplyBlock(Block* block) {
	const int& posY = block->getLocation().y;
	const int& posX = block->getLocation().x;

	const vector<vector<bool> >& array = block->getArray();
	
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (posY + i >= 0 && posX + j >= 0 && posY + i < _height && posX + j < _width && array[i][j]) { 
				_map[posY + i][posX + j] = BlockType::Normal;
			}
		}
	}
	
	block->setChanged(true);
}


void Tetris::RefreshBuffer(Block* block) {
	if (!block->hasChanged()) return;
	
	_printBuf.clear();

	auto tempMap(_map);

	const int& posY = block->getLocation().y;
	const int& posX = block->getLocation().x;

	const vector<vector<bool> >& array = block->getArray();

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (posY + i > 0 && posX + j > 0 && posY + i < _height - 1 
				&& posX + j < _width - 1 && array[i][j])
					tempMap[posY + i][posX + j] = BlockType::Normal;
		}
	}

	for (int i = 0; i < _height; ++i) {
		for (int j = 0; j < _width; ++j) {
			switch(tempMap[i][j]) {
				case BlockType::h_Wall:
					_printBuf += "|";
					break;
				case BlockType::v_Wall:
					_printBuf += "--";
					break;
				case BlockType::Edge:
					_printBuf += "+";
					break;
				case BlockType::Normal:
					_printBuf += "бс";
					break;
				case BlockType::Empty:
					_printBuf += "  ";
					break;
			}
		}
		_printBuf += "\n";
	}
}

void Tetris::PrintBuffer(Block* block) {
	if (block->hasChanged()) {
		system("cls");
		cout << _printBuf << '\n';

		block->setChanged(false);
	}
}

int Tetris::RemoveCompleted() {
	int score;
	
	for (int line = _height - 1; line > 1; --line) {
		if (isCompleteLine(line)) {
			RemoveLine(line);
			++score;
		}
	}
	return score;
}

bool Tetris::isCompleteLine(int line) {
	for (int i = 1; i < _width - 1; ++i) {
		if (_map[line][i] != BlockType::Normal) { return false; }
	}
	return true;
}

void Tetris::RemoveLine(int line) {
	
	for (int i = 1; i < _width - 1; ++i) {
			_map[line][i] = BlockType::Empty;
	}
	
	for (int i = line; i > 1; --line) {
		for (int j = 1; j < _width - 1; ++j) {
			_map[i][j] = _map[i + 1][j];
		}
	}
/*
	for (int i = 1; i < _width; ++i) {
		_map[1][i] = BlockType::Empty;
	}
*/
}

