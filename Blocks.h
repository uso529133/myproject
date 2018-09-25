
#ifndef BLOCKS_H
#define BLOCKS_H

#include "Block.h"

class Block_L : public Block {
public:
	Block_L(int y = 0, int x = 0);
};

class Block_J : public Block {
public:
	Block_J(int y = 0, int x = 0);
};

class Block_O : public Block {
public:
	Block_O(int y = 0, int x = 0);
};

class Block_S : public Block {
public:
	Block_S(int y = 0, int x = 0);
};

class Block_T : public Block {
public:
	Block_T(int y = 0, int x = 0);
};

class Block_Z : public Block {
public:
	Block_Z(int y = 0, int x = 0);
};

class Block_I : public Block {
public:
	Block_I(int y = 0, int x = 0);
};

#endif /* BLOCKS_H */
