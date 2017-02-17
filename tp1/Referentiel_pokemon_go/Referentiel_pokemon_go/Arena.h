#pragma once
#include "Node.h"

class Arena : public Node
{
public:
	Arena();
        Arena(int gain, int respawnLength);
	~Arena();
};

