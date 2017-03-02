#pragma once

#include <stdexcept>
#include "RPGController.h"

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
				theGraph_->addNode(nodeToAdd);
			}
			else if (nodeType == "arene")
			{
				std::shared_ptr<Arena> nodeToAdd = std::make_shared<Arena>(name, gain);
				theGraph_->addNode(nodeToAdd);
			}
			else if (nodeType == "pokestop")
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

std::string RPGController::plusCourtChemin(std::string startKeyNode, unsigned int gainWanted) const
{
	if (!theGraph_->containsNode(startKeyNode))
		throw  std::invalid_argument("Ce noeud n'existe pas.");
	if (gainWanted > 350)
		throw std::out_of_range("Nous n'avons pas trouvé de chemin pour le gain demandé");
	return PathSearcher::ObtainShortestPath(theGraph_, theGraph_->getNode(startKeyNode), gainWanted);
}

std::string RPGController::plusGrandGain(std::string startKeyNode, unsigned int maximumLength) const
{
	if (!theGraph_->containsNode(startKeyNode))
		throw std::invalid_argument("Ce noeud n'existe pas.");
	
	return PathSearcher::ObtainBiggestGain(theGraph_, theGraph_->getNode(startKeyNode), maximumLength);
}
