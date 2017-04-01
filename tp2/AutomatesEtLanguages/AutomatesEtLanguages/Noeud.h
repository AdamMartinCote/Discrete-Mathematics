#include <string>
#include <memory>
#include <vector>

#pragma once
class Noeud
{
public:

#pragma region ConstructeurDestructeur
	/**
	* Le constructor de la racine
	*/
	Noeud(std::string valeur, bool estUnMot, unsigned int niveau);

	/**
	* Le constructeur d'un noeud
	*/
	Noeud::Noeud(std::string valeur, bool estUnMot, unsigned int niveau, std::shared_ptr<Noeud> parent);
	
	/**
	* Le destructeur
	*/
	~Noeud();
#pragma endregion

#pragma region getter
	/**
	* Retourne les enfants du noeud
	* @return le vecteur contenant les enfants du noeud
	*/
	std::vector<std::shared_ptr<Noeud>> obtenirEnfants() const;

	/**
	* Retourne le nombre d'enfants
	* @return le nombre d'enfants que le noeud a
	*/
	int obtenirNombreEnfants() const;

	/**
	* Retourne le noeud parent
	* @return le noeud parent
	*/
	std::shared_ptr<Noeud> obtenirParent() const;

	/**
	* Retourne si le noeud est un mot
	* @return si le noeud est un mot
	*/
	bool estUnMot() const;		 
	
	/**
	* Retourne le niveau
	* @return le niveau
	*/
	unsigned int obtenirNiveau() const;

	/**
	* Retourne la valeur
	* @return la valeur
	*/
	std::string obtenirValeur() const;

	/**
	* Retourne un noeud selon son niveau
	* @param niveau : Le niveau
	* @return le noeud
	*/
	std::vector<std::shared_ptr<Noeud>> obtenirMotsSelonNiveau(int niveau);

	/**
	* Retourne un mot selon son 
	* @param niveau : le niveau
	* @param noeudsTrouves : le noeud avec le mot
	*/
	void obtenirMotSelonNiveau(int niveau, std::shared_ptr<std::vector<std::shared_ptr<Noeud>>> noeudsTrouves);
#pragma endregion

	/**
	* Ajouter un enfant à un noeud
	* @param noeudAAjouter : Le noeud enfant à ajouter
	*/
	void Noeud::ajouterEnfant(std::shared_ptr<Noeud> noeudAAjouter);

	// debug
	/**
	* Afficher les enfants
	*/
	void AfficherEnfants() const;
	/**
	* Affiche le premier mot d'un sous-arbre
	*/
	void AfficherPremierMotDuSousArbre() const;

	/**
	* Met l'attribut estUnMot_ à true
	*/
	void marquerUnMot();

	/**
	* Vérifie si une sous-chaine existe
	* @param sousChaine : La sous-chaine recherché
	* @return si la sous-chaine existe
	*/
	bool verifierSousChaine(std::string sousChaine);
	/**
	* Vérifie si une sous-chaine existe
	* @param sousChaine : La sous-chaine recherché
	* @param SousArbre : Le sous-arbre à parcourir
	* @return si la sous-chaine existe
	*/
	bool verifierSousChaine(std::string sousChaine, std::vector<std::shared_ptr<Noeud>> SousArbre);
private:
	std::string valeur_;
	bool estUnMot_;
	unsigned int niveau_;

	std::shared_ptr<Noeud> parent_;
	std::vector<std::shared_ptr<Noeud>> enfants_;
};

