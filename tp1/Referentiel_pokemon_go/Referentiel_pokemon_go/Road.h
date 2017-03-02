#pragma once

#include "AbstractNode.h"

class Road
{
public:
#pragma region ConstructorDestructor
	//! A default constructor
	Road(std::shared_ptr<AbstractNode> startNode, std::shared_ptr<AbstractNode> endNode, int startGain, int startLength);
	//! A default destructor
	~Road();
#pragma endregion ConstructorDestructor

	//! A function to extend the length of the node.
	/*!
	* \param ptr : node that will take the place of the endNode.
	*/
	void extendTo(std::shared_ptr<AbstractNode> endNode, int edgeLength);

	//! A function that return a readable road with ->.
	/*!
	* \param none
	*/
	std::string toString() const;

#pragma region Getter

	//! A function that get the total gain.
	/*!
	* \param none
	*/
	int GetTotalGain() const;

	//! A function that get the total length
	/*!
	* \param none
	*/
	int GetTotalLength() const;

	//! A function that return the start node.
	/*!
	* \param none
	*/
	std::shared_ptr<AbstractNode> GetStartNode() const;

	//! A function that return the end node.
	/*!
	* \param none
	*/
	std::shared_ptr<AbstractNode> GetEndNode() const;

#pragma endregion Getter

private:
	std::shared_ptr<AbstractNode> startNode_;
	std::shared_ptr<AbstractNode> endNode_;
	int totalGain_;
	int totalLength_;
	std::string readableRoad_;
};