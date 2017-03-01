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
std::string PathSearcher::ObtainShortestPath(std::shared_ptr<Graph> theGraph_, std::shared_ptr<AbstractNode> startNode, unsigned int gainWanted)
{
	std::string path;
	unsigned int actualGain = 0;

	Graph tempGraph;
	tempGraph.addNode(startNode);

	// Rendre infinit tous les chemins en terme de distances.

	std::shared_ptr<Edge> shortestEdge;

	// Tant que nous n'avon pas le gain désiré
	while (actualGain < gainWanted)
	{

		// Pour tous les noeuds choisis
		for (std::shared_ptr<AbstractNode> currentNode : tempGraph.getNodeVector())
		{
			std::shared_ptr<Edge> shortestNodeEdge = NextshortestEdge(currentNode, tempGraph.getNodeVector());
			shortestEdge = (shortestEdge->getLength() > shortestNodeEdge->getLength()) ? shortestNodeEdge : shortestEdge;
		}

		// Ajouter le second noeud au graph temporaire.
		// Ajouter l'autre noeud au graph temporaire.
		// Augmenter le gain

		// Si le gain > gain voulu
			// Créer le chemin partant du noeud de départ au moeud courant.
				// On cherche le plus court chemin du noued courant au noeud de départ
						// tant que le noeud n'est pas le noeud de départ
							// le plus court
	}

	return "";
}

std::shared_ptr<Edge> PathSearcher::NextshortestEdge(std::shared_ptr<AbstractNode> node, std::vector<std::shared_ptr<AbstractNode>> nodesIncluded)
{
	// Pour tous les Edges
		// Si les deux noeuds ne sont pas présent
		// Si la distance est plus courte que la plus courte
			// Prendre ce Edge
	return {};
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


