
#include "Tetris.h"
#include <iostream>
#include <windows.h>
using namespace std;

Tetris::Tetris(int width, int height) 
 : _width(width), _height(height), _map(height, vector<BlockType>(width, BlockType::Empty)), _printBuf(vector<string>(height)), _score(0) { 
 	BuildWalls(); 
	// system("Color 3B"); 
 }

void Tetris::BuildWalls() {
 	for (int i = 0; i < _width; ++i) {
 		// top wall
 		_map[0][i] = BlockType::V_Wall;
 		// bottom wall
 		_map[_height - 1][i] = BlockType::V_Wall;
	 }
	for (int i = 0; i < _height; ++i) {
		// left wall
 		_map[i][0] = BlockType::H_Wall;
 		// right wall
 		_map[i][_width - 1] = BlockType::H_Wall;
	 }
	 _map[0][0] = BlockType::UL_Edge;
	 _map[0][_width - 1] = BlockType::UR_Edge;
	 _map[_height - 1][0] = BlockType::BL_Edge;
	 _map[_height - 1][_width - 1] = BlockType::BR_Edge;
}

bool Tetris::isDuplicateWith(Block* block) {
	int posY = block->getLocation().y;
	int posX = block->getLocation().x;

	const auto& array = block->getArray();

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if ((posY + i >= 0) && (posY + i < _height) && (posX + j >= 0) && (posX + j < _width) && array[i][j] != BlockType::Empty
			&& _map[posY + i][posX + j] != BlockType::Empty ) { return true; }
		}
	}
	
	return false;
}

void Tetris::ApplyBlock(Block* block) {
	int posY = block->getLocation().y;
	int posX = block->getLocation().x;

	const auto& array = block->getArray();
	
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if ((posY + i >= 0) && (posY + i < _height) && (posX + j >= 0) && (posX + j < _width) && array[i][j] != BlockType::Empty) { 
				_map[posY + i][posX + j] = array[i][j];
			}
		}
	}
	
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

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (posY + i > 0 && posX + j > 0 && posY + i < _height - 1 
				&& posX + j < _width - 1 && array[i][j] != BlockType::Empty)
					tempMap[posY + i][posX + j] = array[i][j];
		}
	}

	for (int i = 0; i < _height; ++i) {
		for (int j = 0; j < _width; ++j) {
			switch(tempMap[i][j]) {
				case BlockType::H_Wall:
					_printBuf[i] += "��";
					break;
				case BlockType::V_Wall:
					_printBuf[i] += "��";
					break;
				case BlockType::UL_Edge:
					_printBuf[i] += "��";
					break;
				case BlockType::UR_Edge:
					_printBuf[i] += "��";
					break;
				case BlockType::BL_Edge:
					_printBuf[i] += "��";
					break;
				case BlockType::BR_Edge:
					_printBuf[i] += "��";
					break;
				case BlockType::Special1:
					_printBuf[i] += "��"; 
					break;
				case BlockType::Special2:
					_printBuf[i] += "��"; 
					break;
				case BlockType::Special3:
					_printBuf[i] += "��"; 
					break;
				case BlockType::Normal:
					_printBuf[i] += "��"; 
					break;
				case BlockType::Empty:
					_printBuf[i] += "  ";
					break;
			}
		}
	}
	 
	_printBuf[0] += " ������������������";
	_printBuf[1] += " ��   THE NEXT   ��";
	
	for (int i = 2; i < 7; ++i) {
		_printBuf[i] += " ��  ";
		for (int j = 0; j < 5; ++j) {
			switch(nextArray[i - 2][j]) {
				case BlockType::H_Wall:
					_printBuf[i] += "��";
					break;
				case BlockType::V_Wall:
					_printBuf[i] += "��";
					break;
				case BlockType::UL_Edge:
					_printBuf[i] += "��";
					break;
				case BlockType::UR_Edge:
					_printBuf[i] += "��";
					break;
				case BlockType::BL_Edge:
					_printBuf[i] += "��";
					break;
				case BlockType::BR_Edge:
					_printBuf[i] += "��";
					break;
				case BlockType::Special1:
					_printBuf[i] += "��"; 
					break;
				case BlockType::Special2:
					_printBuf[i] += "��"; 
					break;
				case BlockType::Special3:
					_printBuf[i] += "��"; 
					break;
				case BlockType::Normal:
					_printBuf[i] += "��"; 
					break;
				case BlockType::Empty:
					_printBuf[i] += "  ";
					break;
			}
		}
		_printBuf[i] += string(17 - (_printBuf[i].size() - _width * 2), ' ') + "��";
	}
	_printBuf[7] += " ������������������";
	_printBuf[8] += " ������������������";
	_printBuf[9] += " ��     SCORE    ��";
	_printBuf[10] += " ��              ��";
	_printBuf[11] += " �� " + string(12 - to_string(_score).size(), ' ') + to_string(_score) + " ��";
	_printBuf[12] += " ������������������";
	_printBuf[15] += "  CLI Tetris 0.1";
	_printBuf[17] += "  GITHUB: https:";
	_printBuf[18] += "  //github.com/u";
	_printBuf[19] += "  so529133/simpl";
	_printBuf[20] += "  eTetris.git";
	
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
	
	for (int line = _height - 2; line > 1; --line) {
		while (isCompleteLine(line)) {
			RemoveLine(line);
			++score;
		}
	}
	_score += score * 100;
}

bool Tetris::isCompleteLine(int line) const {
	for (int i = 1; i < _width - 1; ++i) {
		if (_map[line][i] == BlockType::Empty) { return false; }
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

string pauseStr = "* PAUSED *";
string resumeStr = "PRESS 'R' TO RESUME";

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
		
		_sleep(1000);
	}	
}

