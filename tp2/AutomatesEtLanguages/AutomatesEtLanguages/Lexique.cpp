#include "Lexique.h"



Lexique::Lexique()
{
}


Lexique::~Lexique()
{
}

bool Lexique::ajouterArbre(std::shared_ptr<Noeud> noeud)
{
	if (noeud->obtenirParent() != nullptr)
		return false;

	lettresArbres_.push_back(noeud);
	return true;
}

bool Lexique::ajouterNoeud(std::shared_ptr<Noeud> noeudAAjouter, char premierLettre)
{
	std::string lettre(1, premierLettre);
	std::string valeurDuNoeudAAjouter = noeudAAjouter->obtenirValeur();
	std::string valeurDeLarbreCourant;

	for (std::shared_ptr<Noeud> lettreArbre : lettresArbres_)
	{
		valeurDeLarbreCourant = lettreArbre->obtenirValeur();
		if (lettreArbre->obtenirValeur() == lettre)
		{
			// Si le parent a une lettre de moins que l'enfant.
			if (valeurDuNoeudAAjouter.size() == valeurDeLarbreCourant.size() + 1)
			{
				lettreArbre->ajouterEnfant(noeudAAjouter);
				return true;
			}
			// Sinon, on doit poursuivre la recherche.
			else
			{
				return ajouterNoeud(noeudAAjouter, lettreArbre->obtenirEnfants());
			}

			// Si la valeur du noeud a plus d'une lettre.
		}
	}
	return false;
}

// Récursion sur les sous-arbres des arbres de lettre principaux.
bool Lexique::ajouterNoeud(std::shared_ptr<Noeud> noeudAAjouter, std::vector<std::shared_ptr<Noeud>> sousArbre)
{
	std::string valeurDuNoeudAAjouter = noeudAAjouter->obtenirValeur();
	std::string valeurDeLarbreCourant;

	for (std::shared_ptr<Noeud> noeudParent : sousArbre)
	{
		// Si le parent a une lettre de moins que l'enfant.
		if (valeurDuNoeudAAjouter.size() == valeurDeLarbreCourant.size() + 1)
		{
			noeudParent->ajouterEnfant(noeudAAjouter);
			return true;
		}
		// Sinon, on doit poursuivre la recherche.
		else
		{
			return ajouterNoeud(noeudAAjouter, noeudParent->obtenirEnfants());
		}
	}
	return false;
}

bool Lexique::verifierSousChaine(std::string sousChaine)
{
	for (std::shared_ptr<Noeud> lettreArbre : lettresArbres_)
	{
		if (lettreArbre->obtenirValeur() == sousChaine)
			return true;
		else
			return verifierSousChaine(sousChaine, lettreArbre->obtenirEnfants());
	}
	return false;
}

bool Lexique::verifierSousChaine(std::string sousChaine, std::vector<std::shared_ptr<Noeud>> SousArbre)
{
	for (std::shared_ptr<Noeud> noeudParent : SousArbre)
	{
		if (noeudParent->obtenirValeur() == sousChaine)
			return true;
		else
			return verifierSousChaine(sousChaine, noeudParent->obtenirEnfants());
	}
}

bool Lexique::contientLettre(char lettre)
{
	std::string lettreAChercher(1, lettre);
	for (std::shared_ptr<Noeud> arbre : lettresArbres_)
	{
		if (arbre->obtenirValeur() == lettreAChercher)
			return true;
	}
	return false;
}

std::shared_ptr<Noeud> Lexique::ObtenirArbre(char lettre)
{
	std::string lettreAChercher(1, lettre);

	for (std::shared_ptr<Noeud> arbre : lettresArbres_)
	{
		if (arbre->obtenirValeur() == lettreAChercher)
			return arbre;
	}

	return nullptr;
}

std::vector<std::shared_ptr<Noeud>> Lexique::obtenirLesArbres() const
{
	return lettresArbres_;
}
