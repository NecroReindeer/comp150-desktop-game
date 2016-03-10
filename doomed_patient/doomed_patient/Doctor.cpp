#include "stdafx.h"
#include "Doctor.h"
#include "PatientGame.h"

Doctor::Doctor(PatientGame* game)
	: GameObject(game, game->getDoctorSprite())
{
}


Doctor::~Doctor()
{
}
