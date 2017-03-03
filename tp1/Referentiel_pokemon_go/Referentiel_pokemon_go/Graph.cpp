#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <memory>

#include "Pokemon.h"
#include "Pokestop.h"
#include "Arena.h"
#include "Graph.h"


#pragma region ConstructorDestructor
Graph::Graph()
{
}

Graph::Graph(std::string fileName)
{
	std::ifstream inputFile;
	inputFile.open(fileName);

	if (inputFile.is_open()) {

		std::string line, item, field;

		//get first line (nodes)2
		std::getline(inputFile, line);

		std::stringstream node_line_stream(line);

		//parse nodes
		while (std::getline(node_line_stream, item, ';'))
		{
			std::stringstream item_stream(item);

			std::string name;
			std::string nodeType;

			int gain;

			std::getline(item_stream, name, ',');
			std::getline(item_stream, nodeType, ',');
			item_stream >> gain;

			// identify Node type
			if (nodeType == "pokemon")
			{
				std::shared_ptr<Pokemon> nodeToAdd = std::make_shared<Pokemon>(name, gain);
				addNode(nodeToAdd);
			}
			else if (nodeType == "arene")
			{
				std::shared_ptr<Arena> nodeToAdd = std::make_shared<Arena>(name, gain);
				addNode(nodeToAdd);
			}
			else if (nodeType == "pokestop")
			{
				std::shared_ptr<Pokestop> nodeToAdd = std::make_shared<Pokestop>(name, gain);
				addNode(nodeToAdd);
			}
			else
			{
				std::shared_ptr<Arena> nodeToAdd = std::make_shared<Arena>(name, gain);
				addNode(nodeToAdd);
			}

		}

		//get second line (edges)
		std::getline(inputFile, line);

		std::stringstream edge_line_stream(line);

		//parse edges
		while (std::getline(edge_line_stream, item, ';'))
		{
			std::stringstream item_stream(item);

			std::string node1;
			std::string node2;
			int distance;

			std::getline(item_stream, node1, ',');
			std::getline(item_stream, node2, ',');
			item_stream >> distance;

			std::shared_ptr<AbstractNode> ptrToNode1 = getNode(node1);
			std::shared_ptr<AbstractNode> ptrToNode2 = getNode(node2);

			// add the 2 potential node pointers to the new edge
			std::shared_ptr<Edge> ptrEdge = addEdge(ptrToNode1, ptrToNode2, distance);

			ptrToNode1->addEdge(ptrEdge);
			ptrToNode2->addEdge(ptrEdge);
		}
	}
	else std::cout << "Error: coudn't open file" << std::endl;
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

bool Graph::containsNode(std::string keyNode) {
	for (std::shared_ptr<AbstractNode> node : NodeVector_) {
		if (node->getName() == keyNode) {
			return true;
		}
	}
	return false;
}