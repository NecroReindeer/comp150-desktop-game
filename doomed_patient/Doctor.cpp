#include "stdafx.h"
#include "Doctor.h"
#include "PatientGame.h"
#include "LevelCell.h"

Doctor::Doctor(PatientGame* game, VectorXY startCoordinates)
	:NPC(game, startCoordinates, game->getDoctorSprite())
{
}
void Doctor::move(Directions::Direction direction)
{
	centre += Directions::getDirectionVector(direction) * speed;
}