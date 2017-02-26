#include "Pokestop.h"

Pokestop::Pokestop(std::string name, int gain)
	:AbstractNode(name, gain)
{
}

Pokestop::~Pokestop()
{
}

std::string Pokestop::getNodeType() const
{
	return "pokestop";
}
