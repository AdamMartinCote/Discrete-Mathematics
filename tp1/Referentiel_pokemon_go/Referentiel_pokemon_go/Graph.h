#pragma once

#include <vector>
#include "Node.h"

class Graph
{
public:
	Graph();
	Graph(const Graph& toDuplicate);
	~Graph();
private:
	std::vector<Node> NodeVector;
	std::vector<Node> EdgeVector;
};

