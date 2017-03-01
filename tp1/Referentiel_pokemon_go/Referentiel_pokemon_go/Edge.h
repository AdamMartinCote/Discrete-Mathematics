#pragma once
#include <memory>
#include "AbstractNode.h"


class Edge
{
public:
#pragma region ConstructorDestructor
	//! A parametrized constructor for the Edge class
	/*!
	* \param node1 : the first node
	* \param node2 : the second node
	* \param length : the length of the Edge
	*/
	Edge::Edge(std::shared_ptr<AbstractNode> node1, std::shared_ptr<AbstractNode> node2, double length);
	//! A default destructor
	~Edge();
#pragma endregion ConstructorDestructor
	
#pragma region Set
	//! Sets the first Node
	/*!
	* \param node : The Node to set for the firstNode_ attribute
	*/
    void setFirstNode(std::shared_ptr<AbstractNode> node);
	//! Set the second Node
	/*!
	* \param node : The node to set for the secondNode_ attribute
	*/
    void setSecondNode(std::shared_ptr<AbstractNode> node);
	//! Set the length
	/*!
	* \param length : The length to set for the length_ attribute
	*/
    void setLength(double length);
#pragma endregion Set

#pragma region Get
	//! Get the first node
	/*!
	* \result : The first node
	*/
	std::shared_ptr<AbstractNode> getFirstNode() const;
	//! Get the second node
	/*!
	* \result : The second node
	*/
	std::shared_ptr<AbstractNode> getSecondNode() const;
	//! Get the length of the Edge
	/*!
	* \result : The length of the Edge
	*/
    double getLength() const;
#pragma endregion Get

	//! A function to find the other Node attached to the current Edge
	/*!
	* \param node : the first node that we know that is attached to the edge.
	* \result : The other node of the current edge.
	*/
	std::shared_ptr<AbstractNode> getOtherNode(const std::shared_ptr<AbstractNode> node) const;

private:
	std::shared_ptr<AbstractNode> firstNode_;
	std::shared_ptr<AbstractNode> secondNode_;
	double length_;
};

