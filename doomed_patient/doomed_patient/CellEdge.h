#pragma once
#include "Directions.h"

class LevelCell;

class CellEdge
{
public:
	CellEdge(Directions::Direction direction, LevelCell* cell);
	~CellEdge();

	virtual void render(SDL_Renderer* renderer) = 0;

protected:
	Directions::Direction direction;
	LevelCell* cell;

	int centreX;
	int centreY;

};

