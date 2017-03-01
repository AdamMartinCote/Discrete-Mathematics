#pragma once

#include "AbstractNode.h"

class Road
{
public:
#pragma region ConstructorDestructor
	//! A default constructor
	Road(std::shared_ptr<AbstractNode> startNode, std::shared_ptr<AbstractNode> endNode, int startGain);
	//! A default destructor
	~Road();
#pragma endregion ConstructorDestructor
	
	//! A function that add gain to the total gain.
	/*!
	* \param int : gain to add
	*/
	int AddGainAndReturnTotal(int gain);

	//! A function that gets a node from its key (name)
	/*!
	* \param key : name to search for
	*/
	int GetTotalGain() const;

private:
	std::shared_ptr<AbstractNode> startNode_;
	std::shared_ptr<AbstractNode> endNode_;
	int totalGain_;
};