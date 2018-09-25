
#include "Tetris.h"
#include "Block.h"

class TetrisFactory {
public:
	Block* MakeBlock(int y, int x);
	Tetris* MakeTetris(int width, int height);
};

Block* TetrisFactory::MakeBlock(int y, int x) {
	return new Block(y, x);
}

Tetris* TetrisFactory::MakeTetris(int width, int height) {
	return new Tetris(width + 2, height + 2);
}
