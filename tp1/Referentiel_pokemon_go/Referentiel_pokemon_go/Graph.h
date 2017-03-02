#pragma once

#include <vector>
#include "AbstractNode.h"
#include "Edge.h"
#include <memory>
#include "Road.h"

class Graph
{
public:
#pragma region ConstructorDestructor
	//! A default constructor
	Graph();

	//! A duplicate constructor
	/*!
	* \param toDuplicate : the Graph to copy
	*/
	Graph(const Graph& toDuplicate);
	//! A default destructor
	~Graph();
#pragma endregion ConstructorDestructor

	//! A function that tells if an Edge exist
	/*!
	* \param edgeToSearch : The Edge we are looking for
	*/
	bool isEdgeFound(std::shared_ptr<Edge> edgeToSearch) const;

	bool isNodeFound(std::shared_ptr<AbstractNode> nodeToSearch) const;

	//! A function that return the shortest road based on a given gain.
	/*!
	* \param gain : The gain that we are looking for.
	*/
	std::shared_ptr<Road> obtainShortestRoad(std::shared_ptr<AbstractNode> startNode, int gain);


#pragma region Getter

	//! A function that return the whole node vector
	/*!
	* \param none
	*/
	std::vector<std::shared_ptr<AbstractNode>> getNodeVector() const;

	//! A function that gets a node from its key (name)
	/*!
	* \param key : name to search for
	*/
	std::shared_ptr<AbstractNode> getNode(std::string key) const;

	//! A function that gets a road based on the end node.
	/*!
	* \param ptr : end of the node.
	*/
	std::shared_ptr<Road> getRoad(std::shared_ptr<AbstractNode> endNode) const;

#pragma endregion Getter

#pragma region Setter

	//! A function that adds a node given by pointer
	/*!
	* \param nodeToAdd : pointer to the node to be added
	*/
	void addNode(std::shared_ptr<AbstractNode> nodeToAdd);

	//! A function that creates a complete edge.
	/*!
	* \param ptrToNode1, ptrToNode2, length
	*/
	std::shared_ptr<Edge> addEdge(std::shared_ptr<AbstractNode> ptrToNode1, std::shared_ptr<AbstractNode> ptrToNode2, double length);

	//! A function that adds an edge given by pointer
	/*!
	* \param edgeToAdd : pointer to the edge to be added
	*/
	void addEdge(std::shared_ptr<Edge> edgeToAdd);

	//! A function that adds a road given by pointer
	/*!
	* \param roadToAdd : pointer to the road to be added
	*/
	void addRoad(std::shared_ptr<Road> roadToAdd);

#pragma endregion Setter

private:
	std::vector<std::shared_ptr<AbstractNode>> NodeVector_;
	std::vector<std::shared_ptr<Edge>> EdgeVector_;
	std::vector<std::shared_ptr<Road>> RoadVector_;
};

