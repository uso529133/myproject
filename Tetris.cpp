
#include "Tetris.h"
#include <iostream>
#include <windows.h>
using namespace std;

enum BlockType { Empty = 0, v_Wall, h_Wall, Edge, Normal};

Tetris::Tetris(int width, int height) 
 : _width(width), _height(height), _map(height, vector<int>(width, BlockType::Empty)) {
 	BuildWalls();
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
	const int posY = block->getLocation()->y;
	const int posX = block->getLocation()->x;

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
	const int posY = block->getLocation()->y;
	const int posX = block->getLocation()->x;
	
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (posY + i >= 0 && posX + j >= 0 && posY + i < _height && posX + j < _width) { 
				_map[posY + i][posX + j] = BlockType::Normal;
			}
		}
	}
}


void Tetris::RefreshBuffer(Block* block) {
	_printBuf.clear();

	auto tempMap(_map);

	const int posY = block->getLocation()->y;
	const int posX = block->getLocation()->x;

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

void Tetris::PrintBuffer() {
	system("cls");
	cout << _printBuf << '\n';
}
