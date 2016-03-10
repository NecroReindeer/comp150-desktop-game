#include "stdafx.h"
#include "Doctor.h"
#include "PatientGame.h"
#include "LevelCell.h"

Doctor::Doctor(PatientGame* game, std::shared_ptr<LevelCell> cell)
	: GameObject(game, game->getDoctorSprite())
{
	// Calculate the window position from the grid position
	centreX = cell->getCentreX();
	centreY = cell->getCentreY();
}


Doctor::~Doctor()
{
}
