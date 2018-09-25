
#include "Tetris.h"

const int width = 15;
const int height = 20;
	
int main() {
	Tetris game(width, height);
	Block* aBlock = new Block(1, width / 2 - 2);
	
	while (true) {
		aBlock->MoveBy(1, 0);
		if (game.isDuplicateWith(aBlock)) {
			game.ApplyBlock(aBlock);
			aBlock = new Block(1, width / 2 - 2);
		}

		game.RefreshBuffer(aBlock);
		game.PrintBuffer();
		
		_sleep(100);
	}
	
	
	return 0;
}
