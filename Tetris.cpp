
#include "Tetris.h"
#include <iostream>
#include <windows.h>
using namespace std;

enum BlockType { Empty = 0, Normal = 1, v_Wall = 2, h_Wall = 3, Edge = 4};

Tetris::Tetris(int width, int height) 
 : _width(width), _height(height), _map(height, vector<int>(width, BlockType::Empty)), _printBuf(vector<string>(height)), _score(0) { BuildWalls(); }

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


void Tetris::RefreshBuffer(Block* block, Block* nextBlock) {
	if (!block->hasChanged()) return;
	
	for (int i = 0; i < _height; ++i) { _printBuf[i].clear(); }

	auto tempMap(_map);

	const int& posY = block->getLocation().y;
	const int& posX = block->getLocation().x;

	const vector<vector<bool> >& array = block->getArray();
	const vector<vector<bool> >& nextArray = nextBlock->getArray();

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
					_printBuf[i] += "|";
					break;
				case BlockType::v_Wall:
					_printBuf[i] += "--";
					break;
				case BlockType::Edge:
					_printBuf[i] += "+";
					break;
				case BlockType::Normal:
					_printBuf[i] += "бс";
					break;
				case BlockType::Empty:
					_printBuf[i] += "  ";
					break;
			}
		}
	}
	
	_printBuf[0] += " +--------------+";
	_printBuf[1] += " |   THE NEXT   |";
	
	for (int i = 2; i < 7; ++i) {
		_printBuf[i] += " |  ";
		for (int j = 0; j < 5; ++j) {
			switch(nextArray[i - 2][j]) {
				case BlockType::Normal:
					_printBuf[i] += "бс";
					break;
				case BlockType::Empty:
					_printBuf[i] += "  ";
					break;
			}
		}
		_printBuf[i] += string(_width + 7 - _printBuf.size(), ' ') + "|";
	}

	_printBuf[7] += " +--------------+";
	_printBuf[9] += "    * Score: " + to_string(_score);
	
}

const int Tetris::GetScore() {
	return _score;
}

void Tetris::PrintBuffer(Block* block) {
	if (block->hasChanged()) {
		system("cls");
		for (int i = 0; i < _height; ++i) {
			cout << _printBuf[i] << '\n';
		}

		block->setChanged(false);
	}
}

void Tetris::RemoveCompleted() {
	int score = 0;
	
	for (int line = _height - 1; line > 1; --line) {
		while (isCompleteLine(line)) {
			RemoveLine(line);
			++score;
		}
	}
	_score += score * 100;
}

bool Tetris::isCompleteLine(int line) {
	for (int i = 1; i < _width - 1; ++i) {
		if (_map[line][i] != BlockType::Normal) { return false; }
	}
	return true;
}

void Tetris::RemoveLine(int line) {
	for (int i = line; i > 1; --i) {
		for (int j = 1; j < _width - 1; ++j) {
			_map[i][j] = _map[i - 1][j];
		}
	}
	for (int i = 1; i < _width - 1; ++i) {
		_map[1][i] = BlockType::Empty;
	}
}

