#include "stdafx.h"
#include "Directions.h"
#include "VectorXY.h"

Directions::Directions()
{
}


Directions::~Directions()
{
}

VectorXY Directions::getDirectionVector(Direction direction)
{
	int X = rand() % 4;
	int Y = rand() % 3 - 1;
	switch (direction)
	{
	case Directions::Direction::NORTH:
		return VectorXY(0, -1);
	case Directions::Direction::EAST:
		return VectorXY(1, 0);
	case Directions::Direction::SOUTH:
		return VectorXY(0, 1);
	case Directions::Direction::WEST:
		return VectorXY(-1, 0);
	case Directions::Direction::RANDOM:
		return VectorXY(X, Y);
	}
}


Directions::Direction Directions::getOpposite(Direction direction)
{
	switch (direction)
	{
	case Direction::NORTH:
		return Direction::SOUTH;
	case Direction::SOUTH:
		return Direction::NORTH;
	case Direction::EAST:
		return Direction::WEST;
	case Direction::WEST:
		return Direction::EAST;
	}
}
