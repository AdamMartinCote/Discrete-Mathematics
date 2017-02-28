#pragma once

#include <fstream>
#include <string>
#include <sstream>

#include "RPGController.h"
#include "AbstractNode.h"
#include "Edge.h"
#include <iostream>
#include "Pokemon.h"
#include "Arena.h"
#include "Pokestop.h"

#pragma region ConstructorDestructor
RPGController::RPGController()
{
	theGraph_ = nullptr;
}


RPGController::~RPGController()
{
}
#pragma endregion ConstructorDestructor

void RPGController::creerGraphe(std::string fileName)
{
	std::ifstream inputFile;
	inputFile.open(fileName);

	theGraph_ = std::make_unique<Graph>();

	if (inputFile.is_open()) {


		std::string line, item, field;

		//get first line (nodes)
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
			if(nodeType == "pokemon")
			{
				std::shared_ptr<Pokemon> nodeToAdd = std::make_shared<Pokemon>(name, gain);
				theGraph_->addNode(nodeToAdd);
			}
			else if(nodeType == "arene")
			{
				std::shared_ptr<Arena> nodeToAdd = std::make_shared<Arena>(name, gain);
				theGraph_->addNode(nodeToAdd);
			}
			else if(nodeType == "pokestop")
			{
				std::shared_ptr<Pokestop> nodeToAdd = std::make_shared<Pokestop>(name, gain);
				theGraph_->addNode(nodeToAdd);
			}
			else
			{
				std::shared_ptr<Arena> nodeToAdd = std::make_shared<Arena>(name, gain);
				theGraph_->addNode(nodeToAdd);
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

				std::shared_ptr<AbstractNode> ptrToNode1 = theGraph_->getNode(node1);
				std::shared_ptr<AbstractNode> ptrToNode2 = theGraph_->getNode(node2);

				// add the 2 potential node pointers to the new edge
				std::shared_ptr<Edge> ptrEdge = theGraph_->addEdge(ptrToNode1, ptrToNode2, distance);

				ptrToNode1->addEdge(ptrEdge);
				ptrToNode2->addEdge(ptrEdge);
			}
	}
	else std::cout << "files failed to open" << std::endl;
}

void RPGController::lireGraphe() const
{
	if (RPGController::theGraph_ == nullptr) return;

	std::cout << "Affichage des sommets: " << std::endl;
	for (std::shared_ptr<AbstractNode> node : theGraph_->getNodeVector())
	{
		node->printNode();
	}
	std::cout << std::endl;
}

void RPGController::plusCourtChemin(std::string startKeyNode, unsigned int gainWanted) const
{

	std::string path = "";
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
			if(shortestEdge == nullptr)
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

	std::cout << path << std::endl;
}

void RPGController::plusGrandGain(std::shared_ptr<AbstractNode> startingNode, unsigned int maximumLength) const
{
    unsigned int distanceTraveled = 0;
    unsigned int totalGain;
	std::shared_ptr<AbstractNode> currentNode = startingNode;
	std::shared_ptr<AbstractNode> nextNode = startingNode;
    
    unsigned int bestGain = 0;
    
    while(nextNode!= nullptr){
        currentNode = nextNode;
        nextNode = nullptr;
        for (unsigned int i = 0; i < currentNode->getEdgeQuantity(); i++){
			std::shared_ptr<AbstractNode> otherNode = currentNode->getEdges()[i]->getOtherNode(currentNode);
        
            if(distanceTraveled + currentNode->getEdges()[i]->getLength() <= maximumLength &&
                otherNode->getGain() / currentNode->getEdges()[i]->getLength() > bestGain){
                bestGain = otherNode->getGain();
                nextNode = otherNode;
            }
        }
        std::cout << std::endl;
    }
    
    //to continue...
}
