#pragma once
#include "Graph.h"
#include <memory>


#include <fstream>
#include <string>
#include <sstream>

#include "RPGController.h"
#include "AbstractNode.h"
#include "Edge.h"
#include <iostream>
#include "Pokemon.h"
#include "Arena.h"
#include "Pokestop.h"
#include "NodeActivity.h"
#include "PathSearcher.h"

class RPGController
{
public:
#pragma region ConstructorDestructor
	//! A default constructor
	RPGController();
	//! A default destructor
	~RPGController();
#pragma endregion ConstructorDestructor

    //! A function that creates a graph by reading a file.
    /*!
    * \param nomFichier : the file that we are going to extract the graph data from
    */
	void creerGraphe(std::string nomFichier);
        
    //! A function that print all nodes and their edges
	void lireGraphe() const;
        
    //! A function that print the shortest way to get the gain that we want
    /*!
    * \param startingNode : The starting Node
    * \param gainWanted : The gain objective
	* \result : A string with the shortest path
    */
	std::string plusCourtChemin(std::string startingNode, unsigned int gainWanted) const;//TODO la fonction plante si on entre >3500 de gain, restraindre la saisie ??
        
    //! A function that prints the maximum gain given the maximum length
    /*!
    * \param startKeyNode : A string with the name of the first node
	* \param maximumLength : The maximum length we can travel
    * \result : A string with the path with the biggest gain
    */
	std::string plusGrandGain(std::string startKeyNode, unsigned int maximumLength) const;

private:
	std::shared_ptr<Graph> theGraph_;
};

