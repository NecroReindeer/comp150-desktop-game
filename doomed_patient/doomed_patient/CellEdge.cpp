#include "stdafx.h"
#include "CellEdge.h"
#include "Directions.h"
#include "LevelCell.h"


CellEdge::CellEdge(Directions::Direction direction, std::shared_ptr<LevelCell> cell)
	: direction(direction),
	containingCell(cell)
{
}


CellEdge::~CellEdge()
{
}

void CellEdge::initialisePosition()
{
	// For rendering purposes so only necessary if object has a sprite
	if (sprite)
	{
		std::shared_ptr<LevelCell> cell = containingCell.lock();

		switch (direction)
		{
		case Directions::Direction::NORTH:
			centre.x = cell->getCentreX();
			centre.y = cell->getCentreY() - (cell->getSpriteSizeY() / 2 - sprite->getSpriteSizeY() / 2);
			break;
		case Directions::Direction::SOUTH:
			centre.x = cell->getCentreX();
			centre.y = cell->getCentreY() + (cell->getSpriteSizeY() / 2 - sprite->getSpriteSizeY() / 2);
			break;
		case Directions::Direction::EAST:
			centre.x = cell->getCentreX() + (cell->getSpriteSizeX() / 2 - sprite->getSpriteSizeX() / 2);
			centre.y = cell->getCentreY();
			break;
		case Directions::Direction::WEST:
			centre.x = cell->getCentreX() - (cell->getSpriteSizeX() / 2 - sprite->getSpriteSizeX() / 2);
			centre.y = cell->getCentreY();
			break;
		}
	}

}

void CellEdge::render(SDL_Renderer* renderer)
{
	if (sprite)
	{
		sprite->render(renderer, centre, sprite->getSpriteSizeX(), sprite->getSpriteSizeY());
	}
}
