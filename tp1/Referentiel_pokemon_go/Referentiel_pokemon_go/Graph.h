#pragma once

#include <vector>
#include "Node.h"

class Graph
{
public:
	Graph();
	Graph(const Graph& toDuplicate);
	~Graph();

	//! A function that creates and add a node
	/*!
	* \param name, type, gain
	*/
	void addNode(std::string name, std::string type, int gain); 	/// TODO faire de Node une classe abstraite

	//! A function that adds a node given by pointer
	/*!
	* \param nodeToAdd : pointer to the node to be added
	*/
	void addNode(Node* nodeToAdd);

	//! A function that creates and add a node
	/*!
	* \param name, type, gain
	*/
	void addEdge(Node * ptrToNode1, Node * ptrToNode2, double length);

	//! A function that adds an edge given by pointer
	/*!
	* \param edgeToAdd : pointer to the edge to be added
	*/
	void addEdge(Edge * edgeToAdd);

	//! A function that return the whole node vector
	/*!
	* \param nodeToAdd : pointer to the node to be added
	*/
	std::vector<Node*> getNodeVector() const;

	//! A function that gets a node from its key (name)
	/*!
	* \param key : name to search for
	*/
	Node* getNode(std::string key);
private:
	std::vector<Node*> NodeVector_;
	std::vector<Edge*> EdgeVector_;
};

