
#include "BombedTetrisFactory.h"
#include <time.h>

BombedTetrisFactory::BombedTetrisFactory() {
	srand(time(NULL));
}

Block* BombedTetrisFactory::MakeBlock(int width) {
	
	Block* block;
	
	switch(rand() % 7) {
		case 0:
			block = new Block("0000000000111100000000000");
			break;
		case 1:
			block = new Block("0000000100011000100000000");
			break;
		case 2:
			block = new Block("0000001000011000010000000");
			break;
		case 3:
			block = new Block("0000000100001000110000000");
			break;
		case 4:
			block = new Block("0000000100001000011000000");
			break;
		case 5:
			block = new Block("0000001100011000000000000", false);
			break;
		case 6:
			block = new Block("0000000100011100000000000");
			break;
	}
	
	block->MoveBy(0, width / 2 - 2);
	
	return block;
}

Tetris* BombedTetrisFactory::MakeTetris(int width, int height) {
	return new Tetris(width, height);
}
