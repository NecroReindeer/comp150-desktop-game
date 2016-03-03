#include "stdafx.h"
#include "LevelCell.h"
#include "PatientGame.h"


LevelCell::LevelCell(PatientGame* game, int x, int y)
	:GameObject(game, game->getFloorSprite()),
	gridPositionX(x),
	gridPositionY(y)
{
	// Calculate the window position from the grid position
	centreX = gridPositionX * spriteSizeX + spriteSizeX / 2;
	centreY = gridPositionY * spriteSizeY + spriteSizeY / 2;
}


LevelCell::~LevelCell()
{
}
