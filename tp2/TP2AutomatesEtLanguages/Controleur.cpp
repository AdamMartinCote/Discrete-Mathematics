#include <iostream>
#include "Controleur.h"

Controleur::Controleur(): lexique_(new Lexique())
{	

}

Controleur::~Controleur()
{
}

bool Controleur::quitterProgramme = false;

std::shared_ptr<Lexique > Controleur::ObtenirLexique() const
{
	return lexique_;
}

bool Controleur::InitialiserProgramme(std::string cheminFichier)
{
	lexique_ = UsineLexique::initialiserLexiqueOptimise2(cheminFichier);
	return false;
}


std::string Controleur::SuggestionDeMots(std::string motEntree) const
{

	GestionnaireSuggestions gestionnaireSuggestions;
	Lexique lexique;
    return gestionnaireSuggestions.SuggestionsMots(lexique_, motEntree);
	
}

static bool mockCreated = false;
std::string Controleur::VerifierOrthographeDuMot(std::string mot)
{
    /*if (!mockCreated)
	{
		mockCreated = true;
		// Création du MOCK de lexique.
		std::shared_ptr<Noeud> noeauA(new Noeud("a", false, 0)),
			noeudB(new Noeud("ab", true, 1)), noeudC(new Noeud("ac", false, 1));
		lexique_->ajouterArbre(noeauA);
		lexique_->ajouterNoeud(noeudB, 'a');
		lexique_->ajouterNoeud(noeudC, 'a');
    }*/

	return Correcteur::VerifierOrthographeDuMot(mot, lexique_->ObtenirArbreDeLaLettre(mot.at(0)));
}

std::string Controleur::SuggestionCorrection(std::string motEntree) const {
	GestionnaireSuggestions gestionnaireSuggestions;
	std::string resultat = gestionnaireSuggestions.SuggestionsMots(lexique_, motEntree);
	if (resultat == "")
		resultat = Correcteur::VerifierOrthographeDuMot(motEntree, lexique_->ObtenirArbreDeLaLettre(motEntree.at(0)));
	return resultat;
}
