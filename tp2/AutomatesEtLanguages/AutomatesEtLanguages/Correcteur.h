
#include <string>
#include <regex>
#include "Lexique.h"

#pragma once
class Correcteur
{
public:
	Correcteur();
	~Correcteur();
	static std::string VerifierOrthographeDuMot(std::string mot, std::shared_ptr<Noeud> arbreDeLaLettre);
};

