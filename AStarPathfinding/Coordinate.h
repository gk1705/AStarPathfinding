#pragma once

class Coordinate
{
public:
	int x{};
	int y{};

	Coordinate() = default;
	Coordinate(const int x, const int y) : x(x), y(y) {}

	bool operator==(const Coordinate& other) const;
	bool operator!=(const Coordinate& other) const;
	Coordinate operator+(const Coordinate& other) const;
	Coordinate& operator+=(const Coordinate& other);
};