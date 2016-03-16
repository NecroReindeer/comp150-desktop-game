//! Class for 2 dimensional vectors.
/*!
  This is a class for representing 2 dimensional vectors.
  Its uses include grid positions, window positions and
  relative movement, along with calculations relating to
  these.
*/

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

	//! Convert grid coordinates to window coordinates.
	/*!
	  This method converts grid coordinates (this) into
	  window coordinates, using the size of the level cells.
	*/
	VectorXY convertGridToWindow();
};

