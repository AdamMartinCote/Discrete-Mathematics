#include "Noeud.h"



Noeud::Noeud(std::string valeur, bool estUnMot, unsigned int niveau, Noeud parent)
{
}

Noeud::Noeud(std::string valeur, bool estUnMot, unsigned int niveau)
{
}

Noeud::~Noeud()
{
}

std::vector<std::shared_ptr<Noeud>> Noeud::obtenirEnfants() const
{
	return std::vector<std::shared_ptr<Noeud>>();
}

std::shared_ptr<Noeud> Noeud::obtenirParent() const
{
	return parent_;
}

bool Noeud::estUnMot() const
{
	return false;
}

unsigned int Noeud::obtenirNiveau() const
{
	return 0;
}

std::string Noeud::obtenirValeur() const
{
	return std::string();
}

void Noeud::ajouterEnfant(Noeud)
{
}
