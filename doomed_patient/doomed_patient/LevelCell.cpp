#include "stdafx.h"
#include "LevelCell.h"
#include "PatientGame.h"
#include "Directions.h"
#include "CellWall.h"
#include "CellPassage.h"


LevelCell::LevelCell(PatientGame* game, int x, int y)
	: GameObject(game, game->getFloorSprite()),				// Call base class constructor
	gridPositionX(x),
	gridPositionY(y)
{
	// Calculate the window position from the grid position
	centreX = gridPositionX * spriteSizeX + spriteSizeX / 2;
	centreY = gridPositionY * spriteSizeY + spriteSizeY / 2;

	edges[Directions::Direction::NORTH] = nullptr;
	edges[Directions::Direction::EAST] = nullptr;
	edges[Directions::Direction::WEST] = nullptr;
	edges[Directions::Direction::SOUTH] = nullptr;
}


LevelCell::~LevelCell()
{
	delete northEdge;
	delete eastEdge;
	delete southEdge;
	delete westEdge;
}

void LevelCell::render(SDL_Renderer* renderer)
{
	GameObject::render(renderer);

	// Iterate through all map elements
	for (auto& element : edges)
	{
		CellEdge* edge = element.second;
		if (edge)
			edge->render(renderer);
	}
}

bool LevelCell::allEdgesInitialised()
{

	// Iterate through all map elements
	for (auto& element : edges)
	{
		CellEdge* edge = element.second;
		if (!edge)
		{
			return false;
		}
	}

	return true;
	
}

Directions::Direction LevelCell::getRandomUninitialisedDirection()
{
	std::vector<Directions::Direction> uncheckedDirections = {Directions::Direction::NORTH, Directions::Direction::EAST, 
		Directions::Direction::WEST, Directions::Direction::SOUTH};
	for (;;)
	{
		int index = rand() % (uncheckedDirections.size());

		if (!edges[uncheckedDirections[index]])
		{
			return uncheckedDirections[index];
		}
		else
		{
			uncheckedDirections.erase(uncheckedDirections.begin() + index);
		}
	}
}

void LevelCell::createWall(Directions::Direction direction)
{
	edges[direction] = new CellWall(direction, this, game);
}

void LevelCell::createPassage(Directions::Direction direction)
{
	edges[direction] = new CellPassage(direction, this);
}