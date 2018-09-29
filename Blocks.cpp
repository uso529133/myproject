#include "Blocks.h"
#include "BlockData.h"

Block_L::Block_L(int y, int x) : Block(y, x) {
	std::copy( T[0].begin(), T[0].end(), _array.begin() );
};

Block_J::Block_J(int y, int x) : Block(y, x) {
	std::copy( T[1].begin(), T[1].end(), _array.begin() );
};

Block_O::Block_O(int y, int x) : Block(y, x) {
	std::copy( T[2].begin(), T[2].end(), _array.begin() );
	_canRotate = false;
};

Block_S::Block_S(int y, int x) : Block(y, x) {
	std::copy( T[3].begin(), T[3].end(), _array.begin() );
};

Block_T::Block_T(int y, int x) : Block(y, x) {
	std::copy( T[4].begin(), T[4].end(), _array.begin() );
};

Block_Z::Block_Z(int y, int x) : Block(y, x) {
	std::copy( T[5].begin(), T[5].end(), _array.begin() );
};

Block_I::Block_I(int y, int x) : Block(y, x) {
	std::copy( T[6].begin(), T[6].end(), _array.begin() );
};

