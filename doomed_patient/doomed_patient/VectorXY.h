#pragma once
class VectorXY
{
public:
	VectorXY();
	VectorXY(int x, int y);

	int x;
	int y;

	VectorXY operator+(const VectorXY& otherCoord);
	bool operator==(const VectorXY& otherCoord);
};

