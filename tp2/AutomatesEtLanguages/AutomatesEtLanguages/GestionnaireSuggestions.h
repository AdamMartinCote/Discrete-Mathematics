#pragma once

#include <string>
#include <iostream>
#include "Lexique.h"

class GestionnaireSuggestions
{
public:
	GestionnaireSuggestions();
	~GestionnaireSuggestions();

	std::shared_ptr<Noeud> RechercheNoeudMot(std::string motEntree, 
		std::shared_ptr<Noeud> noeudDeRecherche);
	void SuggestionsMots(std::shared_ptr<Lexique> lexique, std::string motEntree) const;
};

