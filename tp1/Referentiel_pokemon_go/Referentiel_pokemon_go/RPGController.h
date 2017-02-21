#pragma once
#include "Graph.h"

class RPGController
{
public:
	RPGController();
	~RPGController();
	
	void creerGraphe(std::string nomFichier);

	void lireGraphe();

	void plusCourtChemin();
	void plusGrandGain();

private:
	Graph* theGraph_;
};

