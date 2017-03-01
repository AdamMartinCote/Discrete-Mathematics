#include "Pokestop.h"

#define RESPAWN_LENGTH_POKESTOP 100

Pokestop::Pokestop(std::string name, int gain)
	:AbstractNode(name, gain)
{
	respawnLength_ = RESPAWN_LENGTH_POKESTOP;
}

Pokestop::~Pokestop()
{
}

std::string Pokestop::getNodeType() const
{
	return "pokestop";
}

std::string Pokestop::getName() const
{
	return name_;
}