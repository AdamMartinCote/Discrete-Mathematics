#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Lexique.h"

class GestionnaireSuggestions
{
public:
	GestionnaireSuggestions();
	~GestionnaireSuggestions();

	std::shared_ptr<Noeud> RechercheNoeudMot(std::string motEntree, 
		std::shared_ptr<Noeud> noeudDeRecherche);
	std::vector<std::string> RemplirTableauSuggestions(std::vector<std::string>& suggestions, std::shared_ptr<Noeud> noeudDepart);
	void SuggestionsMots(std::shared_ptr<Lexique> lexique, std::string motEntree) const;

	friend std::ostream& operator<<(std::ostream& os, const std::vector<std::string> suggestions);
};

