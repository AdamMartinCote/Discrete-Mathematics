#include <iostream>
#include "Controleur.h"

Controleur::Controleur(): lexique_(new Lexique())
{	

}

Controleur::~Controleur()
{
}

bool Controleur::quitterProgramme = false;

bool Controleur::InitialiserProgramme(std::string cheminFichier)
{
	lexique_ = UsineLexique::initialiserLexique(cheminFichier);
	// DEBUG verifie si le lexique est bien chargé (affiche les premieres lettres)
	for (int i = 0; i < lexique_->obtenirLesArbres().size(); i++) {
		std::cout << lexique_->obtenirLesArbres().at(i)->obtenirValeur() << " ";
	}
	return false;
}

static bool mockCreated = false;
std::string Controleur::VerifierOrthographeDuMot(std::string mot)
{
	if (!mockCreated)
	{
		mockCreated = true;
		// Création du MOCK de lexique.
		std::shared_ptr<Noeud> noeauA(new Noeud("a", false, 0)),
			noeudB(new Noeud("ab", true, 1)), noeudC(new Noeud("ac", false, 1));
		lexique_->ajouterArbre(noeauA);
		lexique_->ajouterNoeud(noeudB, 'a');
		lexique_->ajouterNoeud(noeudC, 'a');
	}

	return Correcteur::VerifierOrthographeDuMot(mot, lexique_->ObtenirArbreDeLaLettre(mot.at(0)));
}


