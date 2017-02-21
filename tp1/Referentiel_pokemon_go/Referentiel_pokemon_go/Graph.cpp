#include "Graph.h"



Graph::Graph()
{
}
Graph::Graph(const Graph& toDuplicate)
{
	
}

Graph::~Graph()
{
}

void Graph::addNode(std::string name, std::string type, int gain)
{
	NodeVector_.push_back(new Node(name, type, gain));
}

std::vector<Node*> Graph::getNodeVector()
{
	return NodeVector_;
}
