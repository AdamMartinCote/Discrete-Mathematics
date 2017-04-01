
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
private:
	static std::shared_ptr<Noeud> Correcteur::filtreNoeudsAvecUneSeuleDifference(std::vector<std::shared_ptr<Noeud>> noeuds, std::string mot);
};

