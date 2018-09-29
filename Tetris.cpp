
#include "Tetris.h"
#include <iostream>
#include <windows.h>
using namespace std;

Tetris::Tetris(int width, int height) 
 : _width(width), _height(height), _map(height, vector<BlockType>(width, BlockType::Empty)), _printBuf(vector<string>(height)), _score(0) {}


bool Tetris::CanMoveTo(Block* block, Direction direction) {

	int dy, dx;
	dy = dx = 0;
	
	switch (direction) {
		case Direction::up:
			dy = -1;
			break;
		case Direction::down:
			dy = 1;
			break;
		case Direction::left:
			dx = -1;
			break;
		case Direction::right:
			dx = 1;
			break;
	}

	int posY = block->getLocation().y;
	int posX = block->getLocation().x;

	const auto& array = block->getArray();

	for (int i = 0; i < array.size(); ++i) {
		for (int j = 0; j < array.size(); ++j) {
			if ( array[i][j] != BlockType::Empty && (posY + i + dy >= _height || posY + i + dy < 0 || posX + j + dx >= _width 
				|| posX + j + dx < 0 || _map[posY + i + dy][posX + j + dx] != BlockType::Empty)) return false;
		}
	}
	
	return true;
}

void Tetris::ApplyBlock(Block* block) {
	int posY = block->getLocation().y;
	int posX = block->getLocation().x;

	const auto& array = block->getArray();
	
	for (int i = 0; i < array.size(); ++i) {
		for (int j = 0; j < array.size(); ++j) {
			if ((posY + i >= 0) && (posY + i < _height) && (posX + j >= 0) && (posX + j < _width) && array[i][j] != BlockType::Empty) { 
				_map[posY + i][posX + j] = array[i][j];
			}
		}
	}
	
	ApplyGravity();
	block->setChanged(true);
}


void Tetris::RefreshBuffer(Block* block, Block* nextBlock) {
	if (!block->hasChanged()) return;
	
	for (int i = 0; i < _height; ++i) { _printBuf[i].clear(); }

	auto tempMap(_map);

	int posY = block->getLocation().y;
	int posX = block->getLocation().x;

	const auto& array = block->getArray();
	const auto& nextArray = nextBlock->getArray();

	for (int i = 0; i < array.size(); ++i) {
		for (int j = 0; j < array.size(); ++j) {
			if (posY + i >= 0 && posX + j >= 0 && posY + i < _height - 1 
				&& posX + j < _width && array[i][j] != BlockType::Empty)
					tempMap[posY + i][posX + j] = array[i][j];
		}
	}

	for (int i = 0; i < _height; ++i) {
		_printBuf[i] += "早";
		for (int j = 0; j < _width; ++j) {
			switch(tempMap[i][j]) {
				case BlockType::Special1:
					_printBuf[i] += "≠"; 
					break;
				case BlockType::Special2:
					_printBuf[i] += "﹣"; 
					break;
				case BlockType::Special3:
					_printBuf[i] += "≒"; 
					break;
				case BlockType::Normal:
					_printBuf[i] += "﹥"; 
					break;
				case BlockType::Empty:
					_printBuf[i] += "  ";
					break;
			}
		}
		_printBuf[i] += "早";
	}
	 /*
	_printBuf[0] += " 旨收收收收收收收旬";
	_printBuf[1] += " 早   THE NEXT   早";
	
	for (int i = 2; i < 7; ++i) {
		_printBuf[i] += " 早  ";
		for (int j = 0; j < 5; ++j) {
			switch(nextArray[i - 2][j]) {
				case BlockType::Special1:
					_printBuf[i] += "≠"; 
					break;
				case BlockType::Special2:
					_printBuf[i] += "﹣"; 
					break;
				case BlockType::Special3:
					_printBuf[i] += "≒"; 
					break;
				case BlockType::Normal:
					_printBuf[i] += "﹥"; 
					break;
				case BlockType::Empty:
					_printBuf[i] += "  ";
					break;
			}
		}
		_printBuf[i] += string(17 - (_printBuf[i].size() - _width * 2), ' ') + "早";
	}
	_printBuf[7] += " 曲收收收收收收收旭";
	_printBuf[8] += " 旨收收收收收收收旬";
	_printBuf[9] += " 早     SCORE    早";
	_printBuf[10] += " 早              早";
	_printBuf[11] += " 早 " + string(12 - to_string(_score).size(), ' ') + to_string(_score) + " 早";
	_printBuf[12] += " 曲收收收收收收收旭";
	_printBuf[15] += "  CLI Tetris 0.1";
	_printBuf[17] += "  GITHUB: https:";
	_printBuf[18] += "  //github.com/u";
	_printBuf[19] += "  so529133/simpl";
	_printBuf[20] += "  eTetris.git";
	*/
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

int RemoveAdjacent(vector<vector<BlockType>>& A, int y, int x, BlockType bType) {
	if (y < 0 || x < 0 || y >= A.size() || x >= A[0].size() || A[y][x] != bType || bType == BlockType::Empty)
		return 0;	
	
	A[y][x] = BlockType::Empty;
	
	int connected = 1;
	
	connected += RemoveAdjacent(A, y + 1, x, bType);
	connected += RemoveAdjacent(A, y, x + 1, bType);
	connected += RemoveAdjacent(A, y - 1, x, bType);
	connected += RemoveAdjacent(A, y, x - 1, bType);
		
	return connected;
}

template <class T>
class TD;

void Tetris::RemoveCompleted() {
	int score = 0;
	
	RESTART:
	auto tempArray(_map);
			
	for (int i = _height - 1; i >= 0; --i) {
		for (int j = 0; j < _width; ++j) {
			if (RemoveAdjacent(tempArray, i, j, tempArray[i][j]) >= 3) {
				score += RemoveAdjacent(_map, i, j, _map[i][j]) * 10;
				goto RESTART;
			}
		}
	} 
	
	_score += score * 100;
}

string pauseStr = "* PAUSED *";
string resumeStr = "PRESS 'R' TO RESUME";

void Tetris::ApplyGravity() {
	for (int i = 0; i < _width; ++i) {
		for (int j = _height - 1; j >= 0; --j) {
			if (_map[i][j] != BlockType::Empty) {
				int k = j;
				while (k < _height - 1 && _map[i][k + 1] == BlockType::Empty) {
					_map[i][k + 1] = _map[i][k];
					_map[i][k] = BlockType::Empty;
					k++;
				}
			}
		}
	}
}

void Tetris::PauseGame(Block* block) {
	_printBuf[_height / 2 - 1].replace(_width - pauseStr.size() / 2, pauseStr.size(), pauseStr);
	_printBuf[_height / 2].replace(_width -  resumeStr.size() / 2, resumeStr.size(), resumeStr);

	block->setChanged(true);
	PrintBuffer(block);	
}

void Tetris::ResumeGame(Block* block, Block* nextBlock) {
	block->setChanged(true);
	RefreshBuffer(block, nextBlock);
	
	for (int i = 3; i >= 1; --i) {	
		_printBuf[_height / 2].replace(_width, 1, to_string(i));
		
		block->setChanged(true);
		PrintBuffer(block);	
		
		Sleep(1000);
	}	
}

