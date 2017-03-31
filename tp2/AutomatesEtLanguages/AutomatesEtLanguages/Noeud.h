#include <string>
#include <memory>
#include <vector>

#pragma once
class Noeud
{
public:
	// Constructeur racine
	Noeud(std::string valeur, bool estUnMot, unsigned int niveau);

	// Constructeur noeud
	Noeud::Noeud(std::string valeur, bool estUnMot, unsigned int niveau, std::shared_ptr<Noeud> parent);
	~Noeud();

	std::vector<std::shared_ptr<Noeud>> obtenirEnfants() const;
	int obtenirNombreEnfants() const;
	void Noeud::ajouterEnfant(std::shared_ptr<Noeud> noeudAAjouter);
	std::shared_ptr<Noeud> obtenirParent() const;

	bool estUnMot() const;		 
	

	unsigned int obtenirNiveau() const;
	std::string obtenirValeur() const;

	bool trouverChaineDansSousArbre(std::string) const;

	// debug
	void AfficherEnfants() const;

private:
	std::string valeur_;
	bool estUnMot_;
	unsigned int niveau_;

	std::shared_ptr<Noeud> parent_;
	std::vector<std::shared_ptr<Noeud>> enfants_;
};

