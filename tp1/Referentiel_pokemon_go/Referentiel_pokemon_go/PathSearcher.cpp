#pragma once

#include <iostream>
#include <string>

#include "PathSearcher.h"


#pragma region ConstructorDestructor
PathSearcher::PathSearcher()
{
}


PathSearcher::~PathSearcher()
{
}
std::string PathSearcher::ObtainShortestPath(std::shared_ptr<Graph> theGraph_, std::shared_ptr<AbstractNode> startNode, unsigned int gainWanted)
{
	std::string path;
	unsigned int actualGain = 0;

	std::shared_ptr<Graph> tempGraph = std::make_shared<Graph>();
	tempGraph->addNode(startNode);

	// Rendre infinit tous les chemins en terme de distances.

	std::shared_ptr<Edge> shortestEdge;
	std::shared_ptr<Edge> shortestNodeEdge;
	std::shared_ptr<AbstractNode> otherNode;
	std::shared_ptr<Road> shortestPath;
	std::shared_ptr<AbstractNode> choosedNode;
	std::shared_ptr<AbstractNode> tempNode;


	// Tant que nous n'avon pas le gain désiré
	while (actualGain < gainWanted)
	{
		shortestEdge = nullptr;

		// Pour tous les noeuds choisis
		for (std::shared_ptr<AbstractNode> currentNode : tempGraph->getNodeVector())
		{
			shortestNodeEdge = NextshortestNewEdge(currentNode, tempGraph);

			if ((shortestEdge == nullptr) ||
				(shortestEdge->getLength() > shortestNodeEdge->getLength()))
			{
				shortestEdge = shortestNodeEdge;
				choosedNode = currentNode;
			}
		}

		// Add the node wo wasn't in the temp graph.
		tempGraph->addNode(shortestEdge->getOtherNode(choosedNode));

		// Case of the first loop. We are at the root so there's no road created.
		if (shortestEdge->contains(startNode))
		{
			otherNode = shortestEdge->getOtherNode(startNode);
			shortestPath = std::make_shared<Road>(startNode, otherNode, otherNode->getGain(), shortestEdge->getLength());
			tempGraph->addRoad(shortestPath);
		}
		else
		{
			otherNode = shortestEdge->getOtherNode(choosedNode);
			shortestPath = tempGraph->getRoad(choosedNode);

			// We choose an edge who have a node between a start and end node of a road.
			if (shortestPath == nullptr)
			{
				int lastEdgeLength = 0;
				bool isRoadConnectedToStartNode = false;

				// Search the end node of the road.
				for (std::shared_ptr<Edge> currentEdge : choosedNode->getEdges())
				{
					tempNode = currentEdge->getOtherNode(choosedNode);
					if ((currentEdge != shortestEdge) &&
						tempGraph->isNodeFound(tempNode) &&
						tempGraph->getRoad(tempNode) != nullptr)
					{
						isRoadConnectedToStartNode = true;
						lastEdgeLength = currentEdge->getLength();
						break;
					}
				}

				if (isRoadConnectedToStartNode)
				{
					shortestPath = std::make_shared<Road>(startNode, choosedNode, choosedNode->getGain(), lastEdgeLength);
					shortestPath->extendTo(otherNode, shortestEdge->getLength());
					tempGraph->addRoad(shortestPath);
				}
				else
				{
					throw std::domain_error("It appear that we didn't find a way to link this " +  otherNode->getName() + " to " + startNode->getName() + ".");
				}
			}
			else
			{
				shortestPath->extendTo(otherNode, shortestEdge->getLength());
			}
		}

		actualGain = shortestPath->GetTotalGain();
	}

	return "Gain:" + std::to_string(actualGain) + "\n" + "Chemin:" + shortestPath->toString() + "\n" + "Longueur:" + std::to_string(shortestPath->GetTotalLength()) + "\n";
}

std::shared_ptr<Edge> PathSearcher::NextshortestNewEdge(std::shared_ptr<AbstractNode> node, std::shared_ptr<Graph> graph)
{
	std::shared_ptr<Edge> shortestEdge;
	std::shared_ptr<AbstractNode> otherNode;
	for (std::shared_ptr<Edge> currentEdge : node->getEdges())
	{
		otherNode = currentEdge->getOtherNode(node);
		if (!graph->isNodeFound(otherNode))
		{
			if ((shortestEdge == nullptr) ||
				(shortestEdge->getLength() > currentEdge->getLength())
				)
				shortestEdge = currentEdge;
		}
	}

	if (shortestEdge == nullptr)
		throw std::invalid_argument("The node must at least one edge.");

	return shortestEdge;
}

std::string PathSearcher::ObtainShortestPathWithoutDisjktra(std::shared_ptr<Graph> theGraph_, std::string startKeyNode, unsigned int gainWanted)
{
	std::string path;
	unsigned int actualGain = 0;
	Graph tempGraph;

	auto currentNode = theGraph_->getNode(startKeyNode);
	auto currentEdges = currentNode->getEdges();

	tempGraph.addNode(currentNode);
	actualGain += currentNode->getGain();

	path += currentNode->getName();

	while (actualGain < gainWanted)
	{
		std::shared_ptr<Edge> shortestEdge = nullptr;

		for (std::shared_ptr<Edge> edge : currentEdges)
		{
			if (tempGraph.isEdgeFound(edge))
				continue;
			if (shortestEdge == nullptr)
				shortestEdge = edge;
			else if (
				(edge->getLength() < shortestEdge->getLength()) &&
				(shortestEdge->getOtherNode(currentNode)->isActive())
				)
				shortestEdge = edge;
		}

		currentNode = shortestEdge->getOtherNode(currentNode);
		path += "->" + currentNode->getName();

		tempGraph.addNode(shortestEdge->getOtherNode(currentNode));
		tempGraph.addEdge(shortestEdge);
		actualGain += currentNode->getGain();
		currentEdges = currentNode->getEdges();
	}

	return path;
}

std::string PathSearcher::ObtainBiggestGain(std::shared_ptr<Graph> theGraph_, std::shared_ptr<AbstractNode> startNode, unsigned int maximumLength)
{
	auto currentNode = startNode;
	std::shared_ptr<AbstractNode> nextNode = currentNode;
	std::shared_ptr<Edge> nextEdge = nullptr;
	NodeActivity nodeActivity;

	Graph tempGraph;
	tempGraph.addNode(currentNode);

	std::string path = currentNode->getName();

	unsigned int distanceTraveled = 0;
	unsigned int totalGain = 0;

	while (nextNode != nullptr) {
		currentNode = nextNode;
		nextNode = nullptr;
		for (unsigned int i = 0; i < currentNode->getEdgeQuantity(); i++) {
			unsigned int bestGain = 0;
			std::shared_ptr<AbstractNode> otherNode = currentNode->getEdges()[i]->getOtherNode(currentNode);

			if (distanceTraveled + currentNode->getEdges()[i]->getLength() <= maximumLength &&
				otherNode->getGain() / currentNode->getEdges()[i]->getLength() > bestGain &&
				otherNode->isActive())
			{
				nextNode = otherNode;
				nextEdge = currentNode->getEdges()[i];
				bestGain = nextNode->getGain() / nextEdge->getLength();
			}
		}
		if (nextNode != nullptr) {

			tempGraph.addNode(nextNode);
			tempGraph.addEdge(nextEdge);
			distanceTraveled += nextEdge->getLength();
			totalGain += nextNode->getGain();
			path += "->" + nextNode->getName();
			nodeActivity.setNodeToInactive(currentNode);
			nodeActivity.inactiveNodesManager(nextEdge->getLength());
		}

	}
	nodeActivity.reset();
	return path;
}
#pragma endregion ConstructorDestructor


