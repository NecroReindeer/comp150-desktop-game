#pragma once
#include "Directions.h"

class LevelCell;

class CellEdge
{
public:
	CellEdge(Directions::Direction direction, LevelCell* cell);
	~CellEdge();

protected:
	Directions::Direction direction;
	LevelCell* cell;

	int centreX;
	int centreY;

};

