#pragma once
#include "Node.h"
#include <string>

class Pokemon : public Node
{
public:
	Pokemon(std::string typePokemon);
	~Pokemon();
private:
	std::string typePokemon_;
};

