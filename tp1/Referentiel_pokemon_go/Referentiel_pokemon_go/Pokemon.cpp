#include "Pokemon.h"
#define GAIN_RARE_POKEMON 100
#define GAIN_NORMAL_POKEMON 40
#define GAIN_FREQUENT_POKEMON 10

#define LENGTH_RARE_RESPAWN 500
#define LENGTH_NORMAL_RESPAWN 200
#define LENGTH_FREQUENT_RESPAWN 100

#pragma region ConstructorDestructor
Pokemon::Pokemon(std::string name, int gain) 
	: AbstractNode(name, gain)
{
	if (gain >= GAIN_RARE_POKEMON) { 
		typePokemon_ = PokemonType::rare; 
		respawnLength_ = LENGTH_RARE_RESPAWN;
	}
	else if (gain >= GAIN_NORMAL_POKEMON) {
		typePokemon_ = PokemonType::normal;
		respawnLength_ = LENGTH_NORMAL_RESPAWN;
	}
	else {
		typePokemon_ = PokemonType::frequent;
		respawnLength_ = LENGTH_FREQUENT_RESPAWN;
	}
}

Pokemon::~Pokemon()
{
}
#pragma endregion ConstructorDestructor

std::string Pokemon::getNodeType() const
{
	return "pokemon";
}


