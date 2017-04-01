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
	//lexique_ = UsineLexique::initialiserLexique(cheminFichier);
	lexique_ = UsineLexique::initialiserLexiqueOptimise1(cheminFichier);

	// ************************************************************************************** //
	// DEBUG verifie si le lexique est bien chargé (affiche les premieres lettres)
	std::cout << "liste des racines obtenue: ";
	for (unsigned int i = 0; i < lexique_->obtenirLesArbres().size(); i++) {
		std::cout << lexique_->obtenirLesArbres().at(i)->obtenirValeur() << " ";
	}
	std::cout << std::endl;

	// DEBUG imprime quelque mots du lexique:
	std::cout << "\n sous-arbre [0]:  ";
	lexique_->obtenirLesArbres()[0]->AfficherPremierMotDuSousArbre();
	std::cout << "\n sous-arbre [6]:  ";
	lexique_->obtenirLesArbres()[6]->AfficherPremierMotDuSousArbre();
	std::cout << "\n sous-arbre [19]:  ";
	lexique_->obtenirLesArbres()[19]->AfficherPremierMotDuSousArbre();
	std::cout << std::endl;
	// ************************************************************************************* //

	return false;
}


void Controleur::SuggestionDeMots(std::string motEntree) const
{
	GestionnaireSuggestions gestionnaireSuggestions;
	Lexique lexique;
	gestionnaireSuggestions.SuggestionsMots(lexique_, motEntree);
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
