#pragma once
class VectorXY
{
public:
	VectorXY();
	VectorXY(int x, int y);

	int x;
	int y;

	VectorXY operator+(const VectorXY& otherVector);
	VectorXY operator*(const int& scalar);
	VectorXY operator/(const int& scalar);
	VectorXY& operator+=(const VectorXY& otherVector);
	bool operator==(const VectorXY& otherVector);

	VectorXY convertGridToWindow();
};

