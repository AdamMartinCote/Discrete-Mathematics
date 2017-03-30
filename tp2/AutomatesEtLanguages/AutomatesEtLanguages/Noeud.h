#include <string>
#include <memory>
#include <vector>

#pragma once
class Noeud
{
public:
	// Constructeur racine
	Noeud(std::string valeur, bool estUnMot, unsigned int niveau);

	// Constructeur noeu[df]
	Noeud(std::string valeur, bool estUnMot, unsigned int niveau, Noeud parent);
	~Noeud();

	std::vector<std::shared_ptr<Noeud>> obtenirEnfants() const;

	std::shared_ptr<Noeud> obtenirParent() const;

	bool estUnMot() const;		 
												 
	unsigned int obtenirNiveau() const;
	std::string obtenirValeur() const;
	
	void ajouterEnfant(Noeud);

private:
	std::string valeur_;
	bool estUnMot_;
	unsigned int niveau_;

	std::shared_ptr<Noeud> parent_;
	std::vector<std::shared_ptr<Noeud>> enfants_;
};

