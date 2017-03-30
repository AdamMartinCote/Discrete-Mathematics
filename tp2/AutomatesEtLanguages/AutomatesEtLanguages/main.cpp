#include <iostream>
#include <clocale>

#include "UsineLexique.h"

const int INDICE_LEXIQUE = 1;
int main() {
	setlocale(LC_ALL, "");

	try {
		UsineLexique::initialiserLexique("donnee/lexique" + std::to_string(INDICE_LEXIQUE) + ".txt");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}