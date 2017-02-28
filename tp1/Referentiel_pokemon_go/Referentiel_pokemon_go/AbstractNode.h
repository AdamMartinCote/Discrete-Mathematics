#pragma once
#include<vector>
#include <memory>

#include "NodeType.h"

// forward declarations
class Edge;

class AbstractNode
{
public:
#pragma region ConstructorDestructor
	//! A default constructor
    AbstractNode();
	//! A parametrized constructor. Cannot be used since it's an Abstract class.
	/*!
	* \param name : The name of the Node
	*/
    AbstractNode(std::string name, int gain);
	//! A default destructor
    virtual ~AbstractNode();
#pragma endregion ConstructorDestructor

#pragma region Get
	//! Get the Node type
	/*!
	* \result : The type of the Node
	*/
	virtual std::string getNodeType() const = 0;

	//! Get the gain
	/*!
	* \result : The gain of the node
	*/
	int getGain() const;

	//! Get the respawn length
	/*!
	* \result : The respawn length of the node
	*/
	int getRespawnLength() const;

	//! Get the edge quantity of the node
	/*!
	* \result : The edge quantity of the node
	*/
	unsigned int getEdgeQuantity() const;

	//! Get the Edges vector of the node
	/*!
	* \result : The edge vector of the node
	*/
	std::vector<std::shared_ptr<Edge>> getEdges() const;

	//! Get the name of the node
	/*!
	* \result : The name of the node
	*/
	std::string getName() const;

#pragma endregion Get

#pragma region Set
	//! Set the gain
	/*!
	* \param gain : The gain to set for the gain_ attribute
	*/
	void setGain(int gain);

	//! Set the respawn length
	/*!
	* \param : The length to set for the length_ attribute
	*/
	void setRespawnLength(int respawnLength);

	//! Set isActive to True
	void setToActive();

	//! Set isActive to false
	void setToInactive();
#pragma endregion Set

	//! A function to add a new edge to the Node
	/*!
	* \param edge : The edge to add to the node
	*/
	void addEdge(std::shared_ptr<Edge> edge);

	//! Print the Node on the screen
	void printNode() const;

	//! A function that tell if the node is active or not
	/*!
	* \result : a boolean that tell if the node is active
	*/
	bool isActive() const;

protected:
	std::string name_;
	NodeType nodeType_;
    int gain_;

    bool isActive_;
    int respawnLength_;

	std::vector<std::shared_ptr<Edge>> edgeVector_;
};
