
#ifndef TETRISFACTORY_H
#define TETRISFACTORY_H

#include "Tetris.h"
#include "Blocks.h"

class TetrisFactory {
public:
	TetrisFactory();
	
	virtual Block* MakeBlock(int width);
	virtual Tetris* MakeTetris(int width, int height);
};

#endif /* TETRISFACTORY_H */

