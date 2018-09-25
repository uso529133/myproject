
#include "Tetris.h"
#include "TetrisFactory.h"
#include <conio.h>

const int width = 15;
const int height = 20;

enum Key { Up = 72, Down = 80, Left = 75, Right = 77 };

int main() {

	TetrisFactory   factory;

	int             input;
	int             count = 4;
	
	Tetris* game = factory.MakeTetris(width, height);
	Block* block = factory.MakeBlock(width);
	
	
	while (true) {
		if (count-- == 0) {
			block->MoveBy(1, 0);
			if (game->isDuplicateWith(block)) {
				block->MoveBy(-1, 0);
				game->ApplyBlock(block);
				block = factory.MakeBlock(width);
				
				if (game->isDuplicateWith(block)) {
					game->RefreshBuffer(block);
					game->PrintBuffer(block);
					
					break;
				}
			}
			count = 4;
		}
		
		if (kbhit()) {
			input = getch();
			if (input == 224) {
				switch (getch()) {
					case Key::Up:
						block->Rotate();
						if (game->isDuplicateWith(block)) { block->UnRotate(); }
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
			} else if (input == 32) {
				while (!game->isDuplicateWith(block)) { block->MoveBy(1, 0); }
				block->MoveBy(-1, 0);
				if (game->isDuplicateWith(block)) { break; }
				game->ApplyBlock(block);
				block = factory.MakeBlock(width);
			}
		}
		
		game->RemoveCompleted();
		game->RefreshBuffer(block);
		game->PrintBuffer(block);
		
		_sleep(50);
	}
	
	printf("Game Ended with score %d!\n", game->GetScore());
	
	getchar();
	
	return 0;
}
