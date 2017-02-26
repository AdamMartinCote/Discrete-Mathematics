#pragma once
#include "AbstractNode.h"

class Pokestop : public AbstractNode
{
public:
	Pokestop(std::string name, int gain);
	~Pokestop();
	virtual std::string getNodeType() const override;
};

