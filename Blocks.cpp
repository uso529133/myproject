
#include "Blocks.h"


Block_I::Block_I(int y, int x) : Block(y, x) {
	_array.assign( { {BlockType::Empty, BlockType::Empty, BlockType::Empty, BlockType::Empty, BlockType::Empty}, 
					 {BlockType::Empty, BlockType::Empty, BlockType::Empty, BlockType::Empty, BlockType::Empty}, 
					 {BlockType::Normal, BlockType::Normal, BlockType::Normal, BlockType::Normal, BlockType::Empty}, 
					 {BlockType::Empty, BlockType::Empty, BlockType::Empty, BlockType::Empty, BlockType::Empty}, 
					 {BlockType::Empty, BlockType::Empty, BlockType::Empty, BlockType::Empty, BlockType::Empty} } );
};


