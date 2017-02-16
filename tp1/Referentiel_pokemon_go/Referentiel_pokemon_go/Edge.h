#pragma once
#include "NodeEdge.h"

class Edge
{
public:
	Edge();
	~Edge();
private:
	Node* firstNode;
	Node* secondNode;
};

