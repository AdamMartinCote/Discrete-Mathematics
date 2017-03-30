#include "Noeud.h"



Noeud::Noeud(std::string valeur, bool estUnMot, unsigned int niveau, std::shared_ptr<Noeud> parent)
	:valeur_(valeur), estUnMot_(estUnMot), niveau_(niveau), parent_(parent)
{
}

Noeud::Noeud(std::string valeur, bool estUnMot, unsigned int niveau)
	: valeur_(valeur), estUnMot_(estUnMot), niveau_(niveau)
{
}

Noeud::~Noeud()
{
}

std::vector<std::shared_ptr<Noeud>> Noeud::obtenirEnfants() const
{
	return enfants_;
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
	return valeur_;
}

void Noeud::ajouterEnfant(std::shared_ptr<Noeud> noeudAAjouter)
{
	enfants_.push_back(noeudAAjouter);
}

int Noeud::obtenirNombreEnfants() const {
	return enfants_.size();
}

