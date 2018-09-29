
#ifndef BOMBEDTETRISFACTORY_H
#define BOMBEDTETRISFACTORY_H

#include "Tetris.h"
#include "TetrisFactory.h"
#include "Blocks.h"

class BombedTetrisFactory : public TetrisFactory {
public:
	BombedTetrisFactory();
	
	virtual Block* MakeBlock(int width);
	virtual Tetris* MakeTetris(int width, int height);
};

#endif /* BOMBEDTETRISFACTORY_H */

