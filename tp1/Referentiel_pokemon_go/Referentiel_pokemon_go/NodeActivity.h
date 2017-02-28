#pragma once

#include <vector>
#include "AbstractNode.h"

class NodeActivity
{
public:
	NodeActivity();
	~NodeActivity();

	void setNodeToInactive(std::shared_ptr<AbstractNode> node);

	void removePair(int index);

	void activityController(int length);
private:
	std::vector<std::pair<std::shared_ptr<AbstractNode>, int>> nodes_;
};

