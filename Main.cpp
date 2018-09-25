
#include "Tetris.h"
#include "TetrisFactory.h"

const int width = 15;
const int height = 20;
	
int main() {

	TetrisFactory factory;
	
	Tetris* game = factory.MakeTetris(width, height);
	Block* block = factory.MakeBlock(1, width / 2 - 2);
	
	while (true) {
		block->MoveBy(1, 0);
		if (game->isDuplicateWith(block)) {
			block->MoveBy(-1, 0);
			game->ApplyBlock(block);
			block = factory.MakeBlock(1, width / 2 - 2);
		}

		game->RefreshBuffer(block);
		game->PrintBuffer();
		
		_sleep(100);
	}
	
	
	return 0;
}
