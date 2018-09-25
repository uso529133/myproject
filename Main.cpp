
#include "Tetris.h"
#include "TetrisFactory.h"
#include <conio.h>

const int width = 15;
const int height = 20;

enum Key { Up = 72, Down = 80, Left = 75, Right = 77 };

int main() {

	TetrisFactory factory;
	int input;
	
	Tetris* game = factory.MakeTetris(width, height);
	Block* block = factory.MakeBlock(width);
	
	while (true) {
		block->MoveBy(1, 0);
		if (game->isDuplicateWith(block)) {
			block->MoveBy(-1, 0);
			game->ApplyBlock(block);
			block = factory.MakeBlock(width);
			if (game->isDuplicateWith(block)) {
				printf("Game Over!\n");
				break;
			}
		}
		
		if (kbhit()) {
			int input = getch();
			if (input == 224) {
				switch (getch()) {
					case Key::Up:
						block->Rotate();
						break;
					case Key::Down:
						block->MoveBy(1, 0);
						if (game->isDuplicateWith(block)) { block->MoveBy(-1, 0); }
						break;
					case Key::Left:
						block->MoveBy(0, -1);
						if (game->isDuplicateWith(block)) { block->MoveBy(0, 1); }
						break;
					case Key::Right:
						block->MoveBy(0, 1);
						if (game->isDuplicateWith(block)) { block->MoveBy(0, -1); }
						break;
				}
			}
		}
		
		
		game->RefreshBuffer(block);
		game->PrintBuffer();
		
		_sleep(100);
	}
	
	getchar();
	
	return 0;
}
