#include "Heuristics.h"
#include <cmath>

double Heuristics::calculateHeuristic(const Coordinate& source, const Coordinate& target, HeuristicMethod heuristicMethod)
{
	switch (heuristicMethod)
	{
	case HeuristicMethod::MANHATTAN:
		return manhattan(source, target);
	case HeuristicMethod::EUCLIDEAN:
		return euclidean(source, target);
	case HeuristicMethod::OCTAGONAL:
		return octagonal(source, target);
	default:
		return 0;
	}
}

double Heuristics::manhattan(const Coordinate& source, const Coordinate& target)
{
	const int dx = std::abs(source.x - target.x);
	const int dy = std::abs(source.y - target.y);
	return static_cast<double>(dx + dy);
}

double Heuristics::euclidean(const Coordinate& source, const Coordinate& target)
{
	const int dx = source.x - target.x;
	const int dy = source.y - target.y;
	return std::sqrt(static_cast<double>(dx * dx + dy * dy));
}

double Heuristics::octagonal(const Coordinate& source, const Coordinate& target)
{
	const int dx = std::abs(source.x - target.x);
	const int dy = std::abs(source.y - target.y);
	const double F = std::sqrt(2) - 1;
	return static_cast<double>(dx + dy) + (F - 2) * std::min(dx, dy);
}