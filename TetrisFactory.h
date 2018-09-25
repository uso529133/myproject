
#ifndef TETRISFACTORY_H
#define TETRISFACTORY_H

#include "Tetris.h"
#include "Blocks.h"
#include <time.h>

class TetrisFactory {
public:
	TetrisFactory();
	
	Block* MakeBlock(int width);
	Tetris* MakeTetris(int width, int height);
};

TetrisFactory::TetrisFactory() {
	srand(time(NULL));
}

Block* TetrisFactory::MakeBlock(int width) {
	
	Block* block;

	switch(rand() % 7) {
		case 0:
			block = new Block_L(1, width / 2 - 2);
			break;
		case 1:
			block = new Block_J(1, width / 2 - 2);
			break;
		case 2:
			block = new Block_O(1, width / 2 - 2);
			break;
		case 3:
			block = new Block_S(1, width / 2 - 2);
			break;
		case 4:
			block = new Block_T(1, width / 2 - 2);
			break;
		case 5:
			block = new Block_Z(1, width / 2 - 2);
			break;
		case 6:
			block = new Block_I(1, width / 2 - 2);
			break;
	}
	
	return block;
}

Tetris* TetrisFactory::MakeTetris(int width, int height) {
	return new Tetris(width + 2, height + 2);
}

#endif /* TETRISFACTORY_H */

