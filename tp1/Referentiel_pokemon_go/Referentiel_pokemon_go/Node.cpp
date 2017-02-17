#include "Node.h"
#include "Edge.h"



Node::Node(){}

Node::Node(int gain, int respawnLength)
	:gain_(gain), respawnLength_(respawnLength), isActive_(true){}


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