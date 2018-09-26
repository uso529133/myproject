
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
	void RemoveCompleted();
	const int GetScore();
	// print
	void RefreshBuffer(Block* block, Block* nextBlock);
	void PrintBuffer(Block* block);
	// pause game
	void PauseGame(Block* block);
	void ResumeGame(Block* block, Block* nextBlock);

private: 
	// for RemoveCompleted()
	bool isCompleteLine(int line) const;
	void RemoveLine(int line);
	// for init
	void BuildWalls();
	// map infos
	vector<vector<int> > _map;
	int _width, _height;
	// variables for print
	vector<string> _printBuf;
	int _score;
};

#endif /* TETRIS_H */
