#include "stdafx.h"
#include "GridCoordinate.h"


GridCoordinate::GridCoordinate()
{
}

GridCoordinate::GridCoordinate(int x, int y)
	:x(x), y(y)
{
}


GridCoordinate::~GridCoordinate()
{
}

GridCoordinate GridCoordinate::operator+(const GridCoordinate& otherCoord)
{
	GridCoordinate newCoordinates(x + otherCoord.x, y + otherCoord.y);
	return newCoordinates;
}

bool GridCoordinate::operator==(const GridCoordinate& otherCoord)
{
	return (x == otherCoord.x && y == otherCoord.y);
}