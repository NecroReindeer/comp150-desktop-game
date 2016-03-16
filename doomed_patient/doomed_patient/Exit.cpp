#include "stdafx.h"
#include "Exit.h"
#include "PatientGame.h"
#include "LevelCell.h"


Exit::Exit(PatientGame* game, std::shared_ptr<LevelCell> cell)
	: GameObject(game, game->getExitSprite())
{
	// Calculate the window position from the grid position
	centre.x = cell->getCentre().x;
	centre.y = cell->getCentre().y;
}


Exit::~Exit()
{
}
