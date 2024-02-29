#pragma once

#include "Coordinate.h"

enum class HeuristicMethod
{
	MANHATTAN,
	EUCLIDEAN,
	OCTAGONAL
};

class Heuristics
{
public:
	static double calculateHeuristic(const Coordinate& source, const Coordinate& target, HeuristicMethod heuristicMethod);

private:
	static double manhattan(const Coordinate& source, const Coordinate& target);
	static double euclidean(const Coordinate& source, const Coordinate& target);
	static double octagonal(const Coordinate& source, const Coordinate& target);
};
