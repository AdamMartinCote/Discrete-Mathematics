#include "Arena.h"

//Arena::Arena(){}

Arena::Arena(std::string name, int gain)
	:AbstractNode(name, gain)
{
}

Arena::~Arena() {}

std::string Arena::getNodeType() const
{
	return "arene";
}

