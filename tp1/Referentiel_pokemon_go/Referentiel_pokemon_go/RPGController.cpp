#pragma once

#include <fstream>
#include <string>
#include <sstream>

#include "RPGController.h"
#include "Node.h"
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

			std::stringstream line_stream(line);

			//parse nodes
			while (std::getline(line_stream, item, ';'))
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
		
		// TODO EDGE
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

void RPGController::plusCourtChemin()
{
}

void RPGController::plusGrandGain()
{
}
