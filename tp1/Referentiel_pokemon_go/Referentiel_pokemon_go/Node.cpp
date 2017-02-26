#include <iostream>
#include <string>
#include "Node.h"
#include "Edge.h"
#include <memory>

Node::Node(){}

Node::Node(std::string name, std::string type, int gain)
	:name_(name), nodeType_(type), gain_(gain), isActive_(true)
{}

Node::~Node(){}

void Node::setGain(int gain) {
	gain_ = gain;
}

void Node::setRespawnLength(int respawnLength) {
	respawnLength_ = respawnLength;
}

int Node::getGain() const {
	return gain_;
}

int Node::getRespawnLength() const {
	return respawnLength_;
}

unsigned int Node::getEdgeQuantity() const {
	return edgeVector_.size();
}

std::vector<std::shared_ptr<Edge>> Node::getEdges() const{
    return edgeVector_;
}

void Node::addEdge(std::shared_ptr<Edge> edge) {
	edgeVector_.push_back(edge);
}

void Node::printNode() const
{
	std::cout << "("
		<< name_ << ", "
		<< nodeType_ << ", "
		<< gain_ << ", (";
	// print edges, omitting the starting node for simplicity
	bool isFirstElement = true;
	for(std::shared_ptr<Edge> i : edgeVector_)
	{
		if (!isFirstElement) std::cout << ", ";
		std::cout << "(";
		if (i->getFirstNode()->getName() != this->getName()) std::cout << i->getFirstNode()->getName();
		if (i->getSecondNode()->getName() != this->getName()) std::cout << i->getSecondNode()->getName();
		std::cout << ", " << i->getLength() << ")";
		isFirstElement = false;
	}
	std::cout << ")" << std::endl;
}

std::string Node::getName() const
{
	return name_;
}

bool Node::isActive() const
{
	return isActive_;
}