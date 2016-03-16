#include "stdafx.h"
#include "VectorXY.h"


VectorXY::VectorXY()
{
}

VectorXY::VectorXY(int x, int y)
	:x(x), y(y)
{
}


VectorXY VectorXY::operator+(const VectorXY& otherCoord)
{
	VectorXY newCoordinates(x + otherCoord.x, y + otherCoord.y);
	return newCoordinates;
}

bool VectorXY::operator==(const VectorXY& otherCoord)
{
	return (x == otherCoord.x && y == otherCoord.y);
}