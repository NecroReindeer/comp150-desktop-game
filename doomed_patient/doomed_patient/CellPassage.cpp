#include "stdafx.h"
#include "CellPassage.h"
#include "Directions.h"


CellPassage::CellPassage(Directions::Direction direction, LevelCell* cell)
	: CellEdge(direction, cell)
{
}


CellPassage::~CellPassage()
{
}


void CellPassage::render(SDL_Renderer* renderer)
{
}