
#ifndef TETRIS_H
#define TETRIS_H

#include "Block.h"
#include <string>
using std::string;

enum class Direction { up, down, left, right };

class Tetris {
public:
	Tetris(int width = 10, int height = 15);
	
	bool CanMoveTo(Block* block, Direction direction);
	void ApplyBlock(Block* block);
	// remove completed lines
	virtual void RemoveCompleted();
	const int GetScore();
	// print
	void RefreshBuffer(Block* block, Block* nextBlock);
	void PrintBuffer(Block* block);
	// pause game
	void PauseGame(Block* block);
	void ResumeGame(Block* block, Block* nextBlock);

private: 
	// for RemoveCompleted()
	virtual bool isCompleteLine(int y, int x) const;
	virtual void RemoveLine(int line);
	int GetAdjacent(int y, int x);
	// for init
	void BuildWalls();
	// map infos
	vector<vector<BlockType> > _map;
	int _width, _height;
	// variables for print
	vector<string> _printBuf;
	int _score;
};

#endif /* TETRIS_H */
