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

	std::shared_ptr<Noeud> noeudInitial) {
	std::shared_ptr<Noeud> noeudActuel = noeudInitial;
	for (unsigned int i = 1; i < motEntree.size(); i++) { //Pour toutes les lettres du mot entrée
		for (auto noeud : noeudActuel->obtenirEnfants()) {
			//On vérifie si les enfants du noeud actuel ont la lettre en cours
			if (motEntree[i] == noeud->obtenirValeur()[noeud->obtenirValeur().size() - 1]) {
				//Si oui, le noeud contenant la lettre actuel devient le noeud actuel
				noeudActuel = noeud;
			}
		}
	}
	if (noeudActuel->obtenirValeur() == motEntree)
		//Si on a trouvé un noeud contenant le mot, on le retourne
		return noeudActuel;
	else
		//Sinon on retourne le nullptr pour signifier que rien n'a été trouvé
		return nullptr;
}

std::vector<std::string> GestionnaireSuggestions::RemplirTableauSuggestions(std::vector<std::string>& suggestions, 
	std::shared_ptr<Noeud> noeudDepart) {
	GestionnaireSuggestions gestionnaireSuggestions;
	if (suggestions.size() == NOMBRE_DE_SUGGESTIONS) 
		return suggestions; //Si on a déjà 10 suggestions, retourner le tableau au lieu de continuer à chercher
	else {
		if (noeudDepart->estUnMot()) {
			suggestions.push_back(noeudDepart->obtenirValeur()); //Si on a un mot, le rajouter au vecteur
		}
		for (auto noeud : noeudDepart->obtenirEnfants()) {
			//Réappliquer la fonction sur les enfants du noeud courrant
			suggestions = gestionnaireSuggestions.RemplirTableauSuggestions(suggestions, noeud);
		}
	}
	//S'il n'y a plus de suggestions, retourner le tableau
	return suggestions;
}


void GestionnaireSuggestions::SuggestionsMots(std::shared_ptr<Lexique> lexique, std::string motEntree)const {
	GestionnaireSuggestions gestionnaireSuggestion;
	std::shared_ptr<Noeud> noeudContenantLeMot;

	//On cherche le noeud contenant la première lettre du mot
	for (std::shared_ptr<Noeud> noeud : lexique->ObtenirLettresArbres()) {
		if (noeud->obtenirValeur()[PREMIERE_VALEUR] == motEntree[PREMIERE_VALEUR])
			noeudContenantLeMot = noeud;
	}

	//On cherche le noeud contenant le mot à partir du noeud contenant la première Lettre
	noeudContenantLeMot = gestionnaireSuggestion.RechercheNoeudMot(motEntree, noeudContenantLeMot);
	
	//Si le noeud est le nullptr, on affiche qu'on n'a pas de suggestion
	if (noeudContenantLeMot == nullptr)
		std::cout << "Aucunes suggestions" << std::endl;
	else {
		std::vector<std::string> suggestions;
		//On rempli un vecteur de suggestions
		suggestions = gestionnaireSuggestion.RemplirTableauSuggestions(suggestions, noeudContenantLeMot);
		//On affiche les suggestions
		std::cout << suggestions;
	}
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::string> suggestions) {
	for (std::string suggestion : suggestions) {
		os << suggestion << std::endl;
	}
	return os;
}