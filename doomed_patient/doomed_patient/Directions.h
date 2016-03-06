#pragma once

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

	int getEdgeCentreX(Directions::Direction direction);
	int getEdgeCentreY(Directions::Direction direction);
};

