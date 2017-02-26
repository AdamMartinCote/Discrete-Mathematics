#pragma once
#include <memory>
#include "AbstractNode.h"


class Edge
{
public:
	Edge::Edge(std::shared_ptr<AbstractNode> node1, std::shared_ptr<AbstractNode> node2, double length);
	~Edge();
        
    void setFirstNode(std::shared_ptr<AbstractNode> node);
    void setSecondNode(std::shared_ptr<AbstractNode> node);
    void setLength(double length);
       
	std::shared_ptr<AbstractNode> getFirstNode() const;
	std::shared_ptr<AbstractNode> getSecondNode() const;
    double getLength() const;
	std::shared_ptr<AbstractNode> getOtherNode(const std::shared_ptr<AbstractNode> node) const;

private:
	std::shared_ptr<AbstractNode> firstNode_;
	std::shared_ptr<AbstractNode> secondNode_;
	double length_;
};

