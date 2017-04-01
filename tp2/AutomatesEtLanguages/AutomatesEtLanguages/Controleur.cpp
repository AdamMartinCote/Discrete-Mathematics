#include <iostream>
#include "Controleur.h"

Controleur::Controleur()
{	
}

Controleur::~Controleur()
{
}

bool Controleur::quitterProgramme = false;

bool Controleur::InitialiserProgramme(std::string cheminFichier)
{
	//lexique_ = UsineLexique::initialiserLexique(cheminFichier);
	lexique_ = UsineLexique::initialiserLexiqueOptimise1(cheminFichier);

	// DEBUG verifie si le lexique est bien chargé (affiche les premieres lettres)
	for (unsigned int i = 0; i < lexique_->obtenirLesArbres().size(); i++) {
		std::cout << lexique_->obtenirLesArbres().at(i)->obtenirValeur() << " ";
	}
	return false;
}

std::string Controleur::VerifierOrthographeDuMot(std::string mot)
{
	// Création du MOCK de lexique.
	std::shared_ptr<Noeud> noeauA(new Noeud("a", true, 0)),
		noeudB(new Noeud("ab", true, 1));
	lexique_->ajouterArbre(noeauA);
	lexique_->ajouterNoeud(noeudB, 'a');

	std::string motRetourne = mot;
	// Vérifier si le mot fait partit d'un des mots du lexique.
		// Si oui, retourne le mot. Celui-ci est bien orthographié.
	if(lexique_->verifierSousChaine(mot))
		return motRetourne;

	// Si non, recherche parmi les mots commençant par la même lettre un mot qui s'apparente à celui-ci.
}
