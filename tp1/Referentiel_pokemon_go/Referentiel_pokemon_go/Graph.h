#pragma once

#include <vector>
#include "AbstractNode.h"
#include "Edge.h"
#include <memory>

class Graph
{
public:
	Graph();
	Graph(const Graph& toDuplicate);
	~Graph();

	//! A function that adds a node given by pointer
	/*!
	* \param nodeToAdd : pointer to the node to be added
	*/
	void addNode(std::shared_ptr<AbstractNode> nodeToAdd);

	//! A function that creates and add a node
	/*!
	* \param name, type, gain
	*/
	std::shared_ptr<Edge> addEdge
	(std::shared_ptr<AbstractNode> ptrToNode1, std::shared_ptr<AbstractNode> ptrToNode2, double length);

	//! A function that adds an edge given by pointer
	/*!
	* \param edgeToAdd : pointer to the edge to be added
	*/
	void addEdge(std::shared_ptr<Edge> edgeToAdd);

	//! A function that return the whole node vector
	/*!
	* \param nodeToAdd : pointer to the node to be added
	*/
	std::vector<std::shared_ptr<AbstractNode>> getNodeVector() const;

	//! A function that gets a node from its key (name)
	/*!
	* \param key : name to search for
	*/
	std::shared_ptr<AbstractNode> getNode(std::string key) const;

	bool isEdgeFound(std::shared_ptr<Edge> edgeToSearch) const;
private:
	std::vector<std::shared_ptr<AbstractNode>> NodeVector_;
	std::vector<std::shared_ptr<Edge>> EdgeVector_;
};

