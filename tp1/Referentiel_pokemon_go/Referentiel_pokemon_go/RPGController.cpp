#pragma once

#include <memory>
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
	theGraph_ = std::make_unique<Graph>(fileName);
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
