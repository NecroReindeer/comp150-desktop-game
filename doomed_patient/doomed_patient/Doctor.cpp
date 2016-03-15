#include "stdafx.h"
#include "Doctor.h"
#include "PatientGame.h"

Doctor::Doctor(PatientGame* game, std::shared_ptr<LevelCell> cell)
	:Character(game, cell, game->getDoctorSprite())
{
}