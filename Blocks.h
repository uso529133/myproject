
#include "Block.h"

class Block_T : public Block {
public:
	Block_T(int y = 0, int x = 0);
};

Block_T::Block_T(int y, int x) : Block(y, x) {
	_array.assign( { {1, 0, 0, 0, 1}, 
					 {0, 0, 0, 0, 0}, 
					 {0, 0, 1, 0, 0}, 
					 {0, 0, 0, 0, 0}, 
					 {1, 1, 1, 1, 1} } );
};
