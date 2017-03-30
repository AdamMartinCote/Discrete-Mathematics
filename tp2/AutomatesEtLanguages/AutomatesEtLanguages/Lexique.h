#pragma once
#include <memory>
#include "Noeud.h"

class Lexique
{
public:
	Lexique();
	~Lexique();

	bool verifierSousChaine(std::string sousChaine) const;
private:
	std::vector<std::shared_ptr<Noeud>> arbres;
};

