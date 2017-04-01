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

	bool contientEnfants();
	std::vector<std::shared_ptr<Noeud>> obtenirEnfants() const;
	int obtenirNombreEnfants() const;
	std::vector<std::shared_ptr<Noeud>> obtenirMotsSelonNiveau(int niveau);
	void Noeud::ajouterEnfant(std::shared_ptr<Noeud> noeudAAjouter);
	std::shared_ptr<Noeud> obtenirParent() const;
	bool verifierSousChaine(std::string sousChaine);

	bool estUnMot() const;		 
	

	unsigned int obtenirNiveau() const;
	std::string obtenirValeur() const;

	bool trouverChaineDansSousArbre(std::string) const;

	// debug
	void AfficherEnfants() const;
	void AfficherPremierMotDuSousArbre() const;

	void marquerUnMot();
private:
	std::string valeur_;
	bool estUnMot_;
	unsigned int niveau_;

	std::shared_ptr<Noeud> parent_;
	std::vector<std::shared_ptr<Noeud>> enfants_;

	bool verifierSousChaine(std::string sousChaine, std::vector<std::shared_ptr<Noeud>> SousArbre);
	void Noeud::obtenirMotSelonNiveau(int niveau, std::shared_ptr<std::vector<std::shared_ptr<Noeud>>> noeudsTrouves);
};

