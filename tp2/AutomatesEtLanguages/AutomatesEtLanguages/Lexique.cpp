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
	if (contientLettre(premierLettre))
	{
		return true;
	}
	return false;
}

bool Lexique::verifierSousChaine(std::string sousChaine)
{
	// vérifie si une sous-chaine est contenue dans le lexique
	return false;
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
