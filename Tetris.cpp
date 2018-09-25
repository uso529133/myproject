
#include "Tetris.h"
#include <iostream>
#include <windows.h>
using namespace std;

enum BlockType { Empty = 0, Wall = 1, Normal = 2 };

Tetris::Tetris(int width, int height) 
 : _width(width), _height(height), _map(height, vector<int>(width, BlockType::Empty)) {
 	BuildWalls();
}

void Tetris::BuildWalls() {
 	for (int i = 0; i < _width; ++i) {
 		// top wall
 		_map[0][i] = BlockType::Wall;
 		// bottom wall
 		_map[_height - 1][i] = BlockType::Wall;
	 }
	for (int i = 0; i < _height; ++i) {
		// left wall
 		_map[i][0] = BlockType::Wall;
 		// right wall
 		_map[i][_width - 1] = BlockType::Wall;
	 }
}



bool Tetris::isDuplicateWith(Block block) {
	const int posY = block.getLocation()->y;
	const int posX = block.getLocation()->x;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (posY + i >= 0 && posX + j >= 0 && posY + i < height; 
			&& posX + j < width && _map[posY][posX] != BlockType::Empty ) { return true; }
		}
	}
	
	return false;
}




void Tetris::RefreshBuffer(Block block) {
	_printBuf.clear();

	auto tempMap(_map);

	const int posY = block.getLocation()->y;
	const int posX = block.getLocation()->x;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (posY + i > 0 && posX + j > 0 && posY + i < _height - 1 && posX + j < _width - 1)
				tempMap[posY + i][posX + j] = BlockType::Normal;
		}
	}

	for (int i = 0; i < _height; ++i) {
		for (int j = 0; j < _width; ++j) {
			switch(tempMap[i][j]) {
				case BlockType::Wall:
					_printBuf += "||";
					break;
				case BlockType::Normal:
					_printBuf += "##";
					break;
				default:
					_printBuf += "..";
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
