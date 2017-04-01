#include "GestionnaireSuggestions.h"

#define PREMIERE_VALEUR 0

GestionnaireSuggestions::GestionnaireSuggestions()
{
}


GestionnaireSuggestions::~GestionnaireSuggestions()
{
}

std::shared_ptr<Noeud> GestionnaireSuggestions::RechercheNoeudMot(std::string motEntree, 
	std::shared_ptr<Noeud> noeudDeRecherche) {
	std::shared_ptr<Noeud> temp = noeudDeRecherche;
	for (int i = 1; i < motEntree.size(); i++) {
		for (auto noeud : temp->obtenirEnfants()) {
			if (motEntree[i] == noeud->obtenirValeur()[noeud->obtenirValeur().size() - 1]) {
				temp = noeud;
			}
		}
	}
	if (temp->obtenirValeur() == motEntree)
		return temp;
	else
		return nullptr;
}

void GestionnaireSuggestions::SuggestionsMots(std::shared_ptr<Lexique> lexique, std::string motEntree)const {
	GestionnaireSuggestions gestionnaireSuggestion;
	unsigned int compteur = 0;
	std::shared_ptr<Noeud> temp;
	for (auto noeud : lexique->ObtenirLettresArbres()) {
		if (noeud->obtenirValeur()[PREMIERE_VALEUR] == motEntree[PREMIERE_VALEUR])
			temp = noeud;
	}
	temp = gestionnaireSuggestion.RechercheNoeudMot(motEntree, temp);
	if (temp == nullptr)
		std::cout << "Aucunes suggestions" << std::endl;
}