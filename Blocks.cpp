
#include "Blocks.h"

Block_L::Block_L(int y, int x) : Block(y, x) {
	_array.assign( { {0, 0, 0, 0, 0}, 
					 {0, 1, 0, 0, 0}, 
					 {0, 1, 1, 1, 0}, 
					 {0, 0, 0, 0, 0}, 
					 {0, 0, 0, 0, 0} } );
};

Block_J::Block_J(int y, int x) : Block(y, x) {
	_array.assign( { {0, 0, 0, 0, 0}, 
					 {0, 0, 0, 1, 0}, 
					 {0, 1, 1, 1, 0}, 
					 {0, 0, 0, 0, 0}, 
					 {0, 0, 0, 0, 0} } );
};

Block_O::Block_O(int y, int x) : Block(y, x) {
	_array.assign( { {0, 0, 0, 0, 0}, 
					 {0, 0, 1, 1, 0}, 
					 {0, 0, 1, 1, 0}, 
					 {0, 0, 0, 0, 0}, 
					 {0, 0, 0, 0, 0} } );
	_canRotate = false;
};

Block_S::Block_S(int y, int x) : Block(y, x) {
	_array.assign( { {0, 0, 0, 0, 0}, 
					 {0, 0, 1, 1, 0}, 
					 {0, 1, 1, 0, 0}, 
					 {0, 0, 0, 0, 0}, 
					 {0, 0, 0, 0, 0} } );
};

Block_T::Block_T(int y, int x) : Block(y, x) {
	_array.assign( { {0, 0, 0, 0, 0}, 
					 {0, 0, 1, 0, 0}, 
					 {0, 1, 1, 1, 0}, 
					 {0, 0, 0, 0, 0}, 
					 {0, 0, 0, 0, 0} } );
};

Block_Z::Block_Z(int y, int x) : Block(y, x) {
	_array.assign( { {0, 0, 0, 0, 0}, 
					 {0, 1, 1, 0, 0}, 
					 {0, 0, 1, 1, 0}, 
					 {0, 0, 0, 0, 0}, 
					 {0, 0, 0, 0, 0} } );
};

Block_I::Block_I(int y, int x) : Block(y, x) {
	_array.assign( { {0, 0, 0, 0, 0}, 
					 {0, 0, 0, 0, 0}, 
					 {1, 1, 1, 1, 1}, 
					 {0, 0, 0, 0, 0}, 
					 {0, 0, 0, 0, 0} } );
};


