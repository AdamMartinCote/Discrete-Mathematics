#pragma once
#include "Road.h"


#pragma region ConstructorDestructor
Road::Road(std::shared_ptr<AbstractNode> startNode, std::shared_ptr<AbstractNode> endNode, int startGain, int startLength)
	:startNode_(startNode), endNode_(endNode), totalGain_(startGain), totalLength_(startLength)
{
	readableRoad_ = startNode->getName() + "->" + endNode->getName();
}

Road::~Road()
{
}
#pragma endregion ConstructorDestructor

void Road::extendTo(std::shared_ptr<AbstractNode> endNode, int edgeLength)
{
	endNode_ = endNode;
	readableRoad_ += "->" + endNode->getName();
	totalGain_ += endNode->getGain();
	totalLength_ += edgeLength;
}

std::string Road::toString() const
{
	return readableRoad_;
}

int Road::GetTotalGain() const
{
	return totalGain_;
}

int Road::GetTotalLength() const
{
	return totalLength_;
}

std::shared_ptr<AbstractNode> Road::GetStartNode() const
{
	return startNode_;
}

std::shared_ptr<AbstractNode> Road::GetEndNode() const
{
	return endNode_;
}
