#include "stdafx.h"
#include "CellWall.h"
#include "Directions.h"
#include "PatientGame.h"


CellWall::CellWall(Directions::Direction direction, LevelCell* cell, PatientGame* game)
	: CellEdge(direction, cell)
{
	initialiseWallSprite(game);
	initialiseCentre();
}


CellWall::~CellWall()
{

}


void CellWall::initialiseWallSprite(PatientGame* game)
{

	if (direction == Directions::Direction::NORTH || direction == Directions::Direction::SOUTH)
	{
		wallSprite = game->getHorizontalWallSprite();
	}

	else if (direction == Directions::Direction::EAST || direction == Directions::Direction::WEST)
	{
		wallSprite = game->getVerticalWallSprite();
	}
}

void CellWall::initialiseCentre()
{
	switch (direction)
	{
	case Directions::Direction::NORTH:
		centreX = cell->getCentreX() + (cell->getSpriteSizeX() / 2 - wallSprite->getSpriteSizeX() / 2);
		centreY = cell->getCentreY();
		break;
	case Directions::Direction::SOUTH:
		centreX = cell->getCentreX() - (cell->getSpriteSizeX() / 2 - wallSprite->getSpriteSizeX() / 2);
		centreY = cell->getCentreY();
		break;
	case Directions::Direction::EAST:
		centreX = cell->getCentreX();
		centreY = cell->getCentreY() + (cell->getSpriteSizeY() / 2 - wallSprite->getSpriteSizeY() / 2);
		break;
	case Directions::Direction::WEST:
		centreX = cell->getCentreX();
		centreY = cell->getCentreY() - (cell->getSpriteSizeY() / 2 - wallSprite->getSpriteSizeY() / 2);
		break;
	
	}
}


void CellWall::render(SDL_Renderer* renderer)
{
	wallSprite->render(renderer, centreX, centreY, wallSprite->getSpriteSizeX(), wallSprite->getSpriteSizeY());
}
