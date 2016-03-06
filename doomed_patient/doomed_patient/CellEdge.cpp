#include "stdafx.h"
#include "CellEdge.h"
#include "Directions.h"
#include "LevelCell.h"


CellEdge::CellEdge(Directions::Direction direction, LevelCell* cell)
	: direction(direction),
	cell(cell)
{
}


CellEdge::~CellEdge()
{
}
