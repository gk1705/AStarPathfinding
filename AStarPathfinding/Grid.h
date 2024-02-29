#pragma once

#include <vector>
#include "Coordinate.h"
#include "Node.h"

class Grid
{
public:
	Grid() = default;
	Grid(int width, int height);
	void addObstruction(const Coordinate& obstruction);
	bool isObstructed(int x, int y) const;
	bool isValidCoordinate(const Coordinate& coordinate) const;
	Node getNode(const Coordinate& coordinate) const;
	std::vector<Coordinate> getNeighbors(const Coordinate& coordinate) const;
	std::vector<Coordinate> getNeighborsDiagonally(const Coordinate& coordinate) const;
	int getWidth() const;
	int getHeight() const;

private:
	int width{};
	int height{};
	std::vector<std::vector<Node>> grid;
};