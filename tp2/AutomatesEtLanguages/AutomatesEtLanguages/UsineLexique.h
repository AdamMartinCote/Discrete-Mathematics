#pragma once
#include <fstream>
#include "Lexique.h"

class UsineLexique
{
public:
	UsineLexique();
	~UsineLexique();

	static Lexique initialiserLexique(std::string nomFichier);
};

