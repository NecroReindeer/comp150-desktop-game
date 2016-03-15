#include "stdafx.h"
#include "Character.h"
#include "PatientGame.h"
#include "LevelCell.h"

Character::Character(PatientGame* game, std::shared_ptr<LevelCell> cell, Texture* sprite)
	: GameObject(game, sprite),
	startCoordinates(cell->getCoordinates())
{
	// Calculate the window position from the grid position
	centreX = cell->getCentreX();
	centreY = cell->getCentreY();
}