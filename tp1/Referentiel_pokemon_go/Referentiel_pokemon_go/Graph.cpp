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

void Graph::addNode(Node* nodeToAdd)
{
	NodeVector_.push_back(nodeToAdd);
}

std::vector<Node*> Graph::getNodeVector()
{
	return NodeVector_;
}

Node * Graph::getNode(std::string key)
{
	for(auto aNode : NodeVector_)
	{
		if (key == aNode->getName()) return aNode;
	}
	return nullptr;
}
