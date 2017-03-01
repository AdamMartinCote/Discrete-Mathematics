#pragma once
#include <string>
#include "AbstractNode.h"

enum class PokemonType { rare, normal, frequent };

class Pokemon : public AbstractNode
{
public:
#pragma region ConstructorDestructor
	//! A parametrized constructor
	/*!
	* \param name : The name of the Pokemon
	* \param gain : The gain of the Pokemon
	*/
	Pokemon(std::string name, int gain);
	//! A default destructor
	~Pokemon();
#pragma endregion ConstructorDestructor

	//! Get the Node type
	/*!
	* \result : The type if the node
	*/
	virtual std::string getNodeType() const override;
private:
	PokemonType typePokemon_;
};

