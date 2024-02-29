#pragma once

#include "Coordinate.h"

class Node
{
public:
	Node() = default;
	Node(const Coordinate& position, float g_cost, float h_cost, Node* parent);
	double getFCost() const;
	bool operator==(const Node& other) const;
	bool operator!=(const Node& other) const;
	bool operator>(const Node& other) const;

	Coordinate position;
	float g_cost{};
	float h_cost{};
	Node* parent{};
	bool visited = false;
	bool obstructed = false;
};
