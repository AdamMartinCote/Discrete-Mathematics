#include <iostream>
#include <string>
#include "Node.h"

Node::Node(){}

Node::Node(std::string name, std::string type, int gain)
	:name_(name), nodeType_(type), gain_(gain), isActive_(true)
{}


Node::~Node(){}

void Node::setGain(int gain){
    gain_ = gain;
}

void Node::setRespawnLength(int respawnLength){
    respawnLength_ = respawnLength;
}
        
int Node::getGain(){
    return gain_;
}
       
int Node::getRespawnLength(){
    return respawnLength_;
}

unsigned int Node::getEdgeQuantity(){
    return edgeVector_.size();
}

std::vector<Edge*> Node::getEdges(){
    return edgeVector_;
}

void Node::printNode()
{
	std::cout << "(" 
		<< name_ << ", "
		<< nodeType_ << ", "
		<< gain_ << ", "
		<< "<affichage variable des arcs>"
		<< ")"
		<< std::endl;
}
