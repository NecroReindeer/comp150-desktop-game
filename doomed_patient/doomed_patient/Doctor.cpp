#include "stdafx.h"
#include "Doctor.h"
#include "PatientGame.h"

Doctor::Doctor(PatientGame* game, VectorXY startCoordinates)
	:Character(game, startCoordinates, game->getDoctorSprite())
{
}