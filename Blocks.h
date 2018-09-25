
#include "Block.h"

class Block_T : public Block {
public:
	Block_T(int y = 0, int x = 0);
};

Block_T::Block_T(int y, int x) {
	_array.assign( { {0, 0, 0, 0, 0}, 
					 {0, 0, 0, 0, 0}, 
					 {0, 0, 1, 0, 0}, 
					 {0, 0, 0, 0, 0}, 
					 {0, 0, 0, 0, 0} } );
};
