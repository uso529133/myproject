
#include "TetrisFactory.h"
#include <time.h>

TetrisFactory::TetrisFactory() {
	srand(time(NULL));
}

Block* TetrisFactory::MakeBlock(int width) {
	
	Block* block;
	/*
	switch(rand() % 7) {
		case 0:
			block = new Block_L(0, width / 2 - 2);
			break;
		case 1:
			block = new Block_J(0, width / 2 - 2);
			break;
		case 2:
			block = new Block_O(0, width / 2 - 2);
			break;
		case 3:
			block = new Block_S(0, width / 2 - 2);
			break;
		case 4:
			block = new Block_T(0, width / 2 - 2);
			break;
		case 5:
			block = new Block_Z(0, width / 2 - 2);
			break;
		case 6:
			break;
	}
	*/
	block = new Block_I(-1, width / 2 - 2);
	
	block->Randomize();
	
	return block;
}

Tetris* TetrisFactory::MakeTetris(int width, int height) {
	return new Tetris(width + 2, height + 2);
}
