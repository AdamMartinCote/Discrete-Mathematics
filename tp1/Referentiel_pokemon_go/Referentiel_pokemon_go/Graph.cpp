#include "Graph.h"


#pragma region ConstructorDestructor
Graph::Graph()
{
}
Graph::Graph(const Graph& toDuplicate)
{

}

Graph::~Graph()
{
}
#pragma endregion ConstructorDestructor

#pragma region Get
std::vector<std::shared_ptr<AbstractNode>> Graph::getNodeVector() const
{
	return NodeVector_;
}

std::shared_ptr<AbstractNode> Graph::getNode(std::string key) const
{
	for (auto aNode : NodeVector_)
	{
		if (key == aNode->getName()) return aNode;
	}
	return nullptr;
}

std::shared_ptr<Road> Graph::getRoad(std::shared_ptr<AbstractNode> endNode) const
{
	for(std::shared_ptr<Road> currentRoad : RoadVector_)
	{
		if (currentRoad->GetEndNode() == endNode)
			return currentRoad;
	}

	return nullptr;
}
#pragma endregion Get

//void Graph::addNode(std::string name, std::string type, int gain)
//{
//	
//	NodeVector_.push_back(std::make_shared<AbstractNode>(name, gain));
//}

void Graph::addNode(std::shared_ptr<AbstractNode> nodeToAdd)
{
	NodeVector_.push_back(nodeToAdd);
}

std::shared_ptr<Edge> Graph::addEdge
(std::shared_ptr<AbstractNode> ptrToNode1, std::shared_ptr<AbstractNode> ptrToNode2, double length)
{
	EdgeVector_.push_back(std::make_shared<Edge>(ptrToNode1, ptrToNode2, length));
	return EdgeVector_.back();
}

void Graph::addEdge(std::shared_ptr<Edge> edgeToAdd)
{
	EdgeVector_.push_back(edgeToAdd);
}

void Graph::addRoad(std::shared_ptr<Road> roadToAdd)
{
	RoadVector_.push_back(roadToAdd);
}

bool Graph::isEdgeFound(std::shared_ptr<Edge> edgeToSearch) const {
	for (auto edge : EdgeVector_) {
		if (edgeToSearch == edge)
			return true;
	}
	return false;
}

bool Graph::isNodeFound(std::shared_ptr<AbstractNode> nodeToSearch) const
{
	for(auto node : NodeVector_)
	{
		if (nodeToSearch == node)
			return true;
	}

	return false;
}

std::shared_ptr<Road> Graph::obtainShortestRoad(std::shared_ptr<AbstractNode> startNode, int gain)
{
	std::shared_ptr<Road> shortestRoad = nullptr;
	for (std::shared_ptr<Road> road : RoadVector_)
	{
		if (shortestRoad == nullptr)
			shortestRoad = road;

		if ((road->GetStartNode() == startNode) &&
			(road->GetTotalGain() == gain) &&
			(shortestRoad->GetTotalLength() > road->GetTotalLength())
			)
		{
			shortestRoad = road;
		}
	}

	if (shortestRoad == nullptr)
		throw std::invalid_argument("No road match this gain.");

	return shortestRoad;
}
