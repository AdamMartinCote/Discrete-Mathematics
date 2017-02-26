#pragma once
#include<vector>

// forward declarations
class Edge;

class Node
{
public:
    Node();
    Node(std::string name, std::string type, int gain);
    virtual ~Node();

	void setGain(int gain);

	void Node::setRespawnLength(int respawnLength);

	int getGain() const;

	int getRespawnLength() const;

	unsigned int Node::getEdgeQuantity() const;

    std::vector<Edge*> getEdges() const;

	void addEdge(Edge*);

	void printNode() const;

	std::string getName() const;

	bool isActive() const;

private:
	std::string name_;
	std::string nodeType_;
    int gain_;

    bool isActive_;
    int respawnLength_;

	std::vector<Edge*> edgeVector_;
};
