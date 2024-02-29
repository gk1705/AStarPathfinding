#include "Node.h"

Node::Node(const Coordinate& position, float g_cost, float h_cost, Node* parent)
	: position(position), g_cost(g_cost), h_cost(h_cost), parent(parent)
{
}

double Node::getFCost() const
{
	return g_cost + h_cost;
}

bool Node::operator==(const Node& other) const
{
	return position == other.position;
}

bool Node::operator!=(const Node& other) const
{
	return !(*this == other);
}

bool Node::operator>(const Node& other) const
{
	return getFCost() > other.getFCost();
}
