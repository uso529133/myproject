
#include "Tetris.h"

const int width = 18;
const int height = 20;
	
int main() {
	Tetris game(width, height);
	Block aBlock(1, width / 2 - 3);
	
	while (true) {
		aBlock.MoveBy(1, 0);

		game.RefreshBuffer(aBlock);
		game.PrintBuffer();
		
		_sleep(100);
	}
	
	
	return 0;
}
