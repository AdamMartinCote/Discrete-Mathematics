#pragma once
#include "Road.h"


#pragma region ConstructorDestructor
Road::Road(std::shared_ptr<AbstractNode> startNode, std::shared_ptr<AbstractNode> endNode, int startGain)
	:startNode_(startNode), endNode_(endNode), totalGain_(startGain)
{
}

Road::~Road()
{
}
#pragma endregion ConstructorDestructor

int Road::GetTotalGain() const
{
	return totalGain_;
}

int Road::AddGainAndReturnTotal(int gain)
{
	totalGain_ += gain;
	return totalGain_;
}