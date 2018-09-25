
#ifndef TETRISFACTORY_H
#define TETRISFACTORY_H

#include "Tetris.h"
#include "Block.h"

class TetrisFactory {
public:
	Block* MakeBlock(int width);
	Tetris* MakeTetris(int width, int height);
};

Block* TetrisFactory::MakeBlock(int width) {
	return new Block(1, width / 2 - 2);
}

Tetris* TetrisFactory::MakeTetris(int width, int height) {
	return new Tetris(width + 2, height + 2);
}

#endif /* TETRISFACTORY_H */
