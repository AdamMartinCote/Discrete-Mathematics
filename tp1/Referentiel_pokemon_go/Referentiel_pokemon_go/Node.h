#pragma once
#include "NodeEdge.h"
#include <vector>

class Node
{
public:
	Node(int gain, int respawnLenght);
	virtual ~Node();
private:
	bool isActive_;
	int gain_;
	int respawnLength_;

	std::vector<Edge*> edgeVector;
};
