#include "GestionnaireSuggestions.h"

#define PREMIERE_VALEUR 0
#define NOMBRE_DE_SUGGESTIONS 10

GestionnaireSuggestions::GestionnaireSuggestions()
{
}


GestionnaireSuggestions::~GestionnaireSuggestions()
{
}

std::shared_ptr<Noeud> GestionnaireSuggestions::RechercheNoeudMot(std::string motEntree, 
	std::shared_ptr<Noeud> noeudDeRecherche) {
	std::shared_ptr<Noeud> temp = noeudDeRecherche;
	for (unsigned int i = 1; i < motEntree.size(); i++) {
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

std::vector<std::string> GestionnaireSuggestions::RemplirTableauSuggestions(std::vector<std::string>& suggestions, 
	std::shared_ptr<Noeud> noeudDepart) {
	GestionnaireSuggestions gestionnaireSuggestions;
	if (suggestions.size() == NOMBRE_DE_SUGGESTIONS)
		return suggestions;
	else {
		if (noeudDepart->estUnMot()) {
			suggestions.push_back(noeudDepart->obtenirValeur());
		}
		for (auto noeud : noeudDepart->obtenirEnfants()) {
			suggestions = gestionnaireSuggestions.RemplirTableauSuggestions(suggestions, noeud);
		}
	}
	return suggestions;
}


void GestionnaireSuggestions::SuggestionsMots(std::shared_ptr<Lexique> lexique, std::string motEntree)const {
	GestionnaireSuggestions gestionnaireSuggestion;
	unsigned int compteur = 0;
	std::shared_ptr<Noeud> temp;
	for (std::shared_ptr<Noeud> noeud : lexique->ObtenirLettresArbres()) {
		if (noeud->obtenirValeur()[PREMIERE_VALEUR] == motEntree[PREMIERE_VALEUR])
			temp = noeud;
	}
	temp = gestionnaireSuggestion.RechercheNoeudMot(motEntree, temp);
	if (temp == nullptr)
		std::cout << "Aucunes suggestions" << std::endl;
	else {
		std::cout << "Trouvé" << std::endl;
		std::vector<std::string> suggestions;
		suggestions = gestionnaireSuggestion.RemplirTableauSuggestions(suggestions, temp);
		std::cout << suggestions;
	}
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::string> suggestions) {
	for (std::string suggestion : suggestions) {
		os << suggestion << std::endl;
	}
	return os;
}