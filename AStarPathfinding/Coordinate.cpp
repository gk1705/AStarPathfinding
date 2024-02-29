#include "Coordinate.h"

bool Coordinate::operator==(const Coordinate& other) const
{
	return x == other.x && y == other.y;
}

bool Coordinate::operator!=(const Coordinate& other) const
{
	return !(*this == other);
}

Coordinate Coordinate::operator+(const Coordinate& other) const
{
	return { x + other.x, y + other.y };
}

Coordinate& Coordinate::operator+=(const Coordinate& other)
{
	x += other.x;
	y += other.y;
	return *this;
}
