#pragma once

#include <vector>
#include "Node.h"

class Graph
{
public:
	Graph();
	Graph(const Graph& toDuplicate);
	~Graph();

	/// Permet d'ajouter des Nodes, pour l'instant aucune vérification 
	/// de connexité n'est faite
	/// TODO faire de Node une classe abstraite
	void addNode(std::string name, std::string type, int gain);

	void addNode(Node* nodeToAdd);
	void addEdge();


	std::vector<Node*> getNodeVector();

	Node* getNode(std::string key);
private:

	std::vector<Node*> NodeVector_;
	std::vector<Node*> EdgeVector_;
};

