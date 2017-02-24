#pragma once

#include <fstream>
#include <string>
#include <sstream>

#include "RPGController.h"
#include "Node.h"
#include "Edge.h"
#include <iostream>



RPGController::RPGController()
{
	theGraph_ = nullptr;
}


RPGController::~RPGController()
{
}

void RPGController::creerGraphe(std::string fileName)
{
	std::ifstream inputFile;
	inputFile.open(fileName);
	theGraph_ = new Graph();

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

				theGraph_->addNode(name, nodeType, gain);
				
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


				// trouver node1
				Node * ptrToNode1 = nullptr;
				Node * ptrToNode2 = nullptr;

				for (Node* aNode : theGraph_->getNodeVector())
				{
					if (aNode->getName() == node1) ptrToNode1 = aNode;
				}
				for (Node* aNode : theGraph_->getNodeVector())
				{
					if (aNode->getName() == node2) ptrToNode2 = aNode;
				}

				//theGraph_->addNode(name, nodeType, gain);

			}
	}
}

void RPGController::lireGraphe()
{
	if (RPGController::theGraph_ == nullptr) return;

	std::cout << "Affichage des sommets: " << std::endl;
	for (auto node : theGraph_->getNodeVector())
	{
		node->printNode();
	}
}

void RPGController::plusCourtChemin(Node* startingNode, unsigned int gainWanted)
{
}

void RPGController::plusGrandGain(Node* startingNode, unsigned int maximumLength)
{
    unsigned int distanceTraveled = 0;
    unsigned int totalGain;
    Node* currentNode = startingNode;
    Node* nextNode = nullptr;
    
    unsigned int bestGain = 0;
    
    for (int i = 0; i < currentNode->getEdgeQuantity(); i++){
        Node* otherNode = currentNode->getEdges()[i]->getOtherNode(currentNode);
        
        if(distanceTraveled + currentNode->getEdges()[i]->getLength() <= maximumLength &&
                otherNode->getGain() / currentNode->getEdges()[i]->getLength() > bestGain){
            bestGain = otherNode->getGain();
        }
    }
    
    //to continue...
}
