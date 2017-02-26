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

Edge* Graph::addEdge(Node* ptrToNode1, Node* ptrToNode2, double length)
{
	EdgeVector_.push_back(new Edge(ptrToNode1, ptrToNode2, length));

	return EdgeVector_.back();
}

void Graph::addEdge(Edge * edgeToAdd)
{
	EdgeVector_.push_back(edgeToAdd);
}

bool Graph::isEdgeFound(Edge* edgeToSearch) const{
	for (auto edge : EdgeVector_) {
		if (edgeToSearch == edge)
			return true;
	}
	return false;
}


std::vector<Node*> Graph::getNodeVector() const
{
	return NodeVector_;
}

Node * Graph::getNode(std::string key) const
{
	for(auto aNode : NodeVector_)
	{
		if (key == aNode->getName()) return aNode;
	}
	return nullptr;
}