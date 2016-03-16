#include "stdafx.h"
#include "VectorXY.h"


VectorXY::VectorXY()
{
}

VectorXY::VectorXY(int x, int y)
	:x(x), y(y)
{
}


VectorXY VectorXY::operator+(const VectorXY& otherVector)
{
	VectorXY newVector(x + otherVector.x, y + otherVector.y);
	return newVector;
}

VectorXY VectorXY::operator*(const int& scalar)
{
	VectorXY newVector(x * scalar, y * scalar);
	return newVector;
}

VectorXY VectorXY::operator/(const int& scalar)
{
	VectorXY newVector(x / scalar, y / scalar);
	return newVector;
}

bool VectorXY::operator==(const VectorXY& otherVector)
{
	return (x == otherVector.x && y == otherVector.y);
}