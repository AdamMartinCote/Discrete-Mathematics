#pragma once
#include <string>
#include "AbstractNode.h"

enum class PokemonType { rare, normal, frequent };

class Pokemon : public AbstractNode
{
public:
	Pokemon(std::string name, int gain);
	virtual std::string getNodeType() const override;
	~Pokemon();
private:
	PokemonType typePokemon_;
};

