#pragma once
#include <string>
#include "AbstractNode.h"

class Arena : public AbstractNode
{
public:
    Arena(std::string name, int gain);

	virtual std::string getNodeType() const override;
	~Arena();
};

