#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Lexique.h"

class GestionnaireSuggestions
{
public:
	/**
	* A constructor
	*/
	GestionnaireSuggestions();

	/**
	* A destructor
	*/
	~GestionnaireSuggestions();

	/**
	* Cherche un noeud contenant le mot entrée
	* @param motEntree : Le mot à chercher
	* @param noeudDeRecherche : Le noeud initial
	* @return Si le noeud contenant le mot existe il le retourne, sinon il retourne nullptr
	*/
	std::shared_ptr<Noeud> RechercheNoeudMot(std::string motEntree, 
		std::shared_ptr<Noeud> noeudInitial);
	/**
	* Rempli un vecteur de suggestions
	* @param suggestions : Le vecteur contenant les suggestions
	* @param noeudDepart : Le noeud initial
	* @return Le tableau avec des suggestions
	*/
	std::vector<std::string> RemplirTableauSuggestions(std::vector<std::string>& suggestions, std::shared_ptr<Noeud> noeudDepart);
	
	/**
	* Affiche les suggestions
	* @param lexique : Le lexique dans lequel chercher
	* @param motEntree : Le mot entrée
	*/
	std::string SuggestionsMots(std::shared_ptr<Lexique> lexique, std::string motEntree) const;

	/**
	* Surcharge de l'opérateur << pour afficher un vecteur de string
	* @param os : Le stream contenant la valeur de retour
	* @param suggestions : Le vecteurs de string à afficher
	* @return Le stream contenant les suggestions
	*/
	friend std::ostream& operator<<(std::ostream& os, const std::vector<std::string> suggestions);
};

