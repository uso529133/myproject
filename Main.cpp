
#include "Tetris.h"
#include "BombedTetrisFactory.h"
#include "TetrisFactory.h"
#include <conio.h>

const int width = 15;
const int height = 22;

enum Key { Up = 72, Down = 80, Left = 75, Right = 77 };

int main() {
	BombedTetrisFactory   factory;

	int             input;
	int             count;
	
	Tetris* game = factory.MakeTetris(width, height);
	Block* block = factory.MakeBlock(width);
	Block* nextBlock = factory.MakeBlock(width);
	
	count = 4;
	
	while (true) {
		if (count-- == 0) {
			
			if (game->CanMoveTo(block, Direction::down)) {
				block->MoveBy(1, 0);
			} else {
					game->ApplyBlock(block);
					block = nextBlock;
					nextBlock = factory.MakeBlock(width);
			}
			count = 4;
			
		}
		
		
		if (kbhit()) {
			input = getch();
			if (input == 224) {
				switch (getch()) {
					case Key::Up:
						block->Rotate();
						break;
					case Key::Down:
						if (game->CanMoveTo(block, Direction::down)) { block->MoveBy(1, 0); }
						break;
					case Key::Left:
						if (game->CanMoveTo(block, Direction::left)) { block->MoveBy(0, -1); }
						break;
					case Key::Right:
						if (game->CanMoveTo(block, Direction::right)) { block->MoveBy(0, 1); }
						break;
				}
			} else if (input == 32) {
				while (game->CanMoveTo(block, Direction::down)) { block->MoveBy(1, 0); }
				game->ApplyBlock(block);
				block = nextBlock;
				nextBlock = factory.MakeBlock(width);
				game->RemoveCompleted();
			} else if (input == 'p' || input == 'P') {
				game->PauseGame(block);
				while (true) {
					if (kbhit()) {
						input = getch();
						if (input == 'r' || input =='R') {
							game->ResumeGame(block, nextBlock);
							break;
						}
					}
				}
			}
		}
		
		game->RefreshBuffer(block, nextBlock);
		game->PrintBuffer(block);
		
		_sleep(50);
	}
	
	printf("Game Ended with score %d!\n", game->GetScore());
	
	getchar();
	
	return 0;
}
