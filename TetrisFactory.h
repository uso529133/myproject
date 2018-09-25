
#ifndef TETRISFACTORY_H
#define TETRISFACTORY_H

#include "Tetris.h"
#include "Blocks.h"

class TetrisFactory {
public:
	TetrisFactory();
	
	Block* MakeBlock(int width);
	Tetris* MakeTetris(int width, int height);
};

#endif /* TETRISFACTORY_H */

