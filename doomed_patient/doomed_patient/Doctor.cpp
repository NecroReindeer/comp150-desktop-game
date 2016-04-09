#include "stdafx.h"
#include "Doctor.h"
#include "PatientGame.h"
#include "LevelCell.h"
#include "Character.h"

Doctor::Doctor(PatientGame* game, VectorXY startCoordinates)
	: Character(game, startCoordinates, game->getDoctorSprite())
{
	speed = 1;
}