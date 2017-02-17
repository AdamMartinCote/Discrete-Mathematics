#include "Pokemon.h"
#define GAIN_RARE_POKEMON 100
#define LENGTH_RARE_RESPAWN 500
#define GAIN_NORMAL_POKEMON 40
#define LENGTH_NORMAL_RESPAWN 200
#define GAIN_FREQUENT_POKEMON 10
#define LENGTH_FREQUENT_RESPAWN 100

Pokemon::Pokemon(std::string typePokemon) : typePokemon_(typePokemon)
{
    if (typePokemon == "rare"){
        setGain(GAIN_RARE_POKEMON);
        setRespawnLength(LENGTH_RARE_RESPAWN);
    }
    else if (typePokemon == "normal"){
        setGain(GAIN_NORMAL_POKEMON);
        setRespawnLength(LENGTH_NORMAL_RESPAWN);
    }
    else if (typePokemon == "frequent"){
        setGain(GAIN_FREQUENT_POKEMON);
        setRespawnLength(LENGTH_FREQUENT_RESPAWN);
    }
}


Pokemon::~Pokemon()
{
}