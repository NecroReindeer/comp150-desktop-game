#include "stdafx.h"
#include "Character.h"
#include "PatientGame.h"
#include "LevelCell.h"

Character::Character(PatientGame* game, std::shared_ptr<LevelCell> cell, Texture* sprite)
	: GameObject(game, sprite),
	startCoordinates(cell->getCoordinates())
{
	// Calculate the window position from the grid position
	centre.x = cell->getCentre().x;
	centre.y = cell->getCentre().y;
}