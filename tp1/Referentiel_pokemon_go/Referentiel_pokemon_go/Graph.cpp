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

void Graph::addEdge(Node* ptrToNode1, Node* ptrToNode2, double length)
{
}

void Graph::addEdge(Edge * edgeToAdd)
{
	EdgeVector_.push_back(edgeToAdd);
}

std::vector<Node*> Graph::getNodeVector() const
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