#pragma once
#include "Graph.h"
#include <memory>

class RPGController
{
public:
	//! A default constructor
	RPGController();
	//! A default destructor
	~RPGController();
	
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
    */
	void plusCourtChemin(std::string startingNode, unsigned int gainWanted) const;
        
    //! A function that prints the maximum gain given the maximum length
    /*!
    * \param node : the first node that we know that is attached to the edge. 
    * \result : The other node of the current edge.
    */
	void plusGrandGain(Node* startingNode, unsigned int maximumLength) const;

private:
	std::unique_ptr<Graph> theGraph_;
};

