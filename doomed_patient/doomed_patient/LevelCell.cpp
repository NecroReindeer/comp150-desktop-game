#include "stdafx.h"
#include "LevelCell.h"
#include "PatientGame.h"
#include "Directions.h"
#include "CellWall.h"


LevelCell::LevelCell(PatientGame* game, int x, int y)
	: GameObject(game, game->getFloorSprite()),				// Call base class constructor
	gridPositionX(x),
	gridPositionY(y)
{
	// Calculate the window position from the grid position
	centreX = gridPositionX * spriteSizeX + spriteSizeX / 2;
	centreY = gridPositionY * spriteSizeY + spriteSizeY / 2;

	northEdge = new CellWall(Directions::Direction::NORTH, this, game);
	eastEdge = new CellWall (Directions::Direction::EAST, this, game);
	southEdge = new CellWall(Directions::Direction::SOUTH, this, game);
	westEdge = new CellWall (Directions::Direction::WEST, this, game);

	edges[0] = northEdge;
	edges[1] = eastEdge;
	edges[2] = westEdge;
	edges[3] = southEdge;
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
	for each (CellWall* edge in edges)
	{
		edge->render(renderer);
	}
}