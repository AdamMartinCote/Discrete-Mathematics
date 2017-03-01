#pragma once

#include "Graph.h"
#include "NodeActivity.h"

class PathSearcher
{
public:
#pragma region ConstructorDestructor
	//! A default constructor
	PathSearcher();
	//! A default destructor
	~PathSearcher();
#pragma endregion ConstructorDestructor

	//! A function that prints the shortest path given a gain that we want
	/*!
	* \param theGraph_ : the graph on which we calculate the biggest gain
	* \param startNode : The starting node
	* \param gainWanted : The gain that we want
	* \result : A string the path with the shortest path
	*/
	static std::string PathSearcher::ObtainShortestPath(std::shared_ptr<Graph> theGraph_, std::shared_ptr<AbstractNode> startNode, unsigned int gainWanted);

	//! A function that prints the shortest without using Disjktra
	/*!
	* \param theGraph_ : the graph on which we calculate the biggest gain
	* \param startKeyNode : The name of the starting node
	* \param gainWanted : The gain that we want
	* \result : A string the path with the shortest path
	*/
	static std::string ObtainShortestPathWithoutDisjktra(std::shared_ptr<Graph>  theGraph_, std::string startKeyNode, unsigned int gainWanted);

	//! A function that prints the maximum gain given the maximum length
	/*!
	* \param theGraph_ : the graph on which we calculate the biggest gain
	* \param startNode : The starting node
	* \param maximumLength : The maximum lenght we can travel
	* \result : A string the path with the biggest gain
	*/
	static std::string ObtainBiggestGain(std::shared_ptr<Graph> theGraph_, std::shared_ptr<AbstractNode> startNode, unsigned int maximumLength);

private:

	static std::shared_ptr<Edge> PathSearcher::NextshortestEdge(std::shared_ptr<AbstractNode> node, std::vector<std::shared_ptr<AbstractNode>> nodesIncluded);
};