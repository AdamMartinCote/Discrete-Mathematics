#pragma once
#include<vector>
#include <memory>

#include "NodeType.h"

// forward declarations
class Edge;

class AbstractNode
{
public:
    AbstractNode();
    AbstractNode(std::string name, int gain);
    virtual ~AbstractNode();

	virtual std::string getNodeType() const = 0;

	void setGain(int gain);

	void setRespawnLength(int respawnLength);

	int getGain() const;

	int getRespawnLength() const;

	unsigned int getEdgeQuantity() const;

    std::vector<std::shared_ptr<Edge>> getEdges() const;

	void addEdge(std::shared_ptr<Edge> edge);

	void printNode() const;

	std::string getName() const;

	bool isActive() const;

protected:
	std::string name_;
	NodeType nodeType_;
    int gain_;

    bool isActive_;
    int respawnLength_;

	std::vector<std::shared_ptr<Edge>> edgeVector_;
};
