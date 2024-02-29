#include "Grid.h"

Grid::Grid(const int width, const int height) : width(width), height(height)
{
	grid.resize(height, std::vector<Node>(width));
}

void Grid::addObstruction(const Coordinate& obstruction)
{
	if (isValidCoordinate(obstruction))
	{
		grid[obstruction.y][obstruction.x].obstructed = true;
	}
}

bool Grid::isObstructed(const int x, const int y) const
{
	if (isValidCoordinate(Coordinate{ x, y }))
	{
		return grid[y][x].obstructed;
	}
	return true;
}

bool Grid::isValidCoordinate(const Coordinate& coordinate) const
{
	return coordinate.x >= 0 && coordinate.x < width && coordinate.y >= 0 && coordinate.y < height;
}

Node Grid::getNode(const Coordinate& coordinate) const
{
	if (isValidCoordinate(coordinate))
	{
		return grid[coordinate.y][coordinate.x];
	}
	return Node(Coordinate(-1, -1), -1, -1, nullptr);
}

std::vector<Coordinate> Grid::getNeighbors(const Coordinate& coordinate) const
{
	std::vector<Coordinate> neighbors;
	constexpr int neighborCoords[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	for (int i = 0; i < 4; ++i)
	{
		const int newX = coordinate.x + neighborCoords[i][0];
		const int newY = coordinate.y + neighborCoords[i][1];
		Coordinate neighbor(newX, newY);
		if (isValidCoordinate(neighbor) && !isObstructed(newX, newY))
		{
			neighbors.push_back(neighbor);
		}
	}

	return neighbors;
}

std::vector<Coordinate> Grid::getNeighborsDiagonally(const Coordinate& coordinate) const
{
	std::vector<Coordinate> neighbors;
	for (int dx = -1; dx <= 1; ++dx)
	{
		for (int dy = -1; dy <= 1; ++dy)
		{
			if (dx == 0 && dy == 0) continue;

			const int newX = coordinate.x + dx;
			const int newY = coordinate.y + dy;
			Coordinate neighbor(newX, newY);
			if (isValidCoordinate(neighbor) && !isObstructed(newX, newY))
			{
				neighbors.push_back(neighbor);
			}
		}
	}
	return neighbors;
}

int Grid::getWidth() const
{
	return width;
}

int Grid::getHeight() const
{
	return height;
}