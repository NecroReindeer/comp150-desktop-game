#pragma once
#include "GridCoordinate.h"

class Directions
{
public:

	enum class Direction
	{
		NORTH,
		EAST,
		SOUTH,
		WEST
	};

	Directions();
	~Directions();

	static GridCoordinate getDirectionVector(Direction direction);
	static Direction getOpposite(Direction direction);
};

