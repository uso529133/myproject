
class AbstractTetrisFactory {
public:
	TetrisFactory() = 0;
	
	virtual Block* MakeBlock(int width, ) = 0;
	virtual Tetris* MakeTetris(int width, int height) = 0;
};
