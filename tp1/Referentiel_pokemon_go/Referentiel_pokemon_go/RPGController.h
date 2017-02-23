#pragma once
#include "Graph.h"

class RPGController
{
public:
	RPGController();
	~RPGController();
	
        //! A function that creates a graph by reading a file.
        /*!
         * \param nomFichier : the file that we are going to extract the graph data from
        */
	void creerGraphe(std::string nomFichier);
        
        //! Print
        /*!
         * A function that prints the graph informations.
         */
	void lireGraphe();
        
        //! A function that print the shortest way to get the gain that we want
        /*!
         * \param startingNode : The starting Node
         * \param gainWanted : The gain objective
         */
	void plusCourtChemin(Node & startingNode, unsigned int gainWanted);
        
        //! A function that prints the maximum gain given the maximum length
        /*!
         * \param node : the first node that we know that is attached to the edge. 
         * \result : The other node of the current edge.
         */
	void plusGrandGain(Node & startingNode, unsigned int maximumLength);

private:
	Graph* theGraph_;
};

