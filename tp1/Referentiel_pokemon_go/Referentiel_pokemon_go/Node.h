#pragma once
#include<vector>
#include<string>

// forward declarations
class Edge;

class Node
{
public:
    Node();
    Node(std::string name, std::string type, int gain);
    virtual ~Node();
        
    void setGain(int gain);
    void setRespawnLength(int respawnLength);
    
    int getGain();
    int getRespawnLength();
    unsigned int getEdgeQuantity();
    std::vector<Edge*> getEdges();

	void printNode();

private:
	std::string name_;
	std::string nodeType_;
    int gain_;

    bool isActive_;
    int respawnLength_;

	std::vector<Edge*> edgeVector_;
};
