#pragma once

#include <vector>
#include "AbstractNode.h"

class NodeActivity
{
public:
#pragma region ConstructorDestructor
	//! A default constructor
	NodeActivity();
	//! A destructor
	~NodeActivity();
#pragma endregion ConstructorDestructor

	//! A function that set to Inactive a node
	/*!
	* \param node : The node to make inactive
	*/
	void setNodeToInactive(std::shared_ptr<AbstractNode> node);

	//! A function that remove a pair from the inactive nodes
	/*!
	* \param index : The index of the pair to remove
	*/
	void removePair(int index);

	void setArenaActive();

	//! A function that tells if an Edge exist
	/*!
	* \param length : The length travelled
	*/
	void activityController(int length);
private:
	std::vector<std::pair<std::shared_ptr<AbstractNode>, int>> nodes_;
	std::vector<std::shared_ptr<AbstractNode>> arenas_;
};

