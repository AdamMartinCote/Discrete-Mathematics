#pragma once

#include <string>

#include "PathSearcher.h"


#pragma region ConstructorDestructor
PathSearcher::PathSearcher()
{
}


PathSearcher::~PathSearcher()
{
}
std::string PathSearcher::ObtainShortestPath()
{
	return "";
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

std::string PathSearcher::ObtainBiggestGain()
{
	return "";
}
#pragma endregion ConstructorDestructor


