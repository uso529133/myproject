
#ifndef TETRIS_H
#define TETRIS_H

#include "Block.h"
#include <string>
using std::string;

class Tetris {
public:
	Tetris(int width = 10, int height = 15);
	
	bool isDuplicateWith(Block* block);
	void ApplyBlock(Block* block);
	// remove completed lines
	int RemoveCompleted();
	// print
	void RefreshBuffer(Block* block);
	void PrintBuffer();

private:
	// for RemoveCompleted()
	bool isCompleteLine(int line);
	void RemoveLine(int line);
	// for init
	void BuildWalls();
	// map infos
	vector<vector<int> > _map;
	int _width, _height;
	// buffer for print
	string _printBuf;
};

#endif /* TETRIS_H */
