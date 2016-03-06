#include "stdafx.h"
#include "CellWall.h"
#include "Directions.h"
#include "PatientGame.h"


CellWall::CellWall(Directions::Direction direction, LevelCell* cell, PatientGame* game)
	: CellEdge(direction, cell)
{
	initialiseSprite(game);
	initialisePosition();
}


CellWall::~CellWall()
{

}


void CellWall::initialiseSprite(PatientGame* game)
{

	if (direction == Directions::Direction::NORTH || direction == Directions::Direction::SOUTH)
	{
		sprite = game->getHorizontalWallSprite();
	}

	else if (direction == Directions::Direction::EAST || direction == Directions::Direction::WEST)
	{
		sprite = game->getVerticalWallSprite();
	}
}


