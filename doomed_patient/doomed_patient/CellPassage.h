#pragma once
#include "CellEdge.h"
class CellPassage :
	public CellEdge
{
public:
	CellPassage(Directions::Direction direction, LevelCell* cell);
	~CellPassage();

	void render(SDL_Renderer* renderer);

};

