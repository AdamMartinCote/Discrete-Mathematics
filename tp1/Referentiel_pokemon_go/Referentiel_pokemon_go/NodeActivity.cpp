#include "NodeActivity.h"


#pragma region ConstructorDestructor
NodeActivity::NodeActivity()
{
}


NodeActivity::~NodeActivity()
{
}
#pragma endregion ConstructorDestructor

void NodeActivity::inactiveNodesManager(int length) {
	for (int i = 0; i < nodes_.size(); i++) {
		nodes_[i].second -= length;
		if (nodes_[i].second <= 0) {
			removePair(i);
			i--;
		}
	}
}

void NodeActivity::setNodeToInactive(std::shared_ptr<AbstractNode> node)
{
	if (node->getNodeType() != "arene") {
		std::pair<std::shared_ptr<AbstractNode>, int> temp;
		temp.first = node;
		temp.second = node->getRespawnLength();
		nodes_.push_back(temp);
	}
	else {
		arenas_.push_back(node);
	}
	node->setToInactive();
}

void NodeActivity::removePair(int index) {
	nodes_[index] = nodes_[nodes_.size() - 1];
	nodes_.pop_back();
}

void NodeActivity::reset() {
	for (int i = 0; i < arenas_.size(); i++)
		arenas_[i]->setToActive();

	for (int i = 0; i < nodes_.size(); i++)
		nodes_[i].first->setToActive();
}