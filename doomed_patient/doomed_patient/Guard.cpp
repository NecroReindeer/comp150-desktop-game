#include "stdafx.h"
#include "Guard.h"
#include "PatientGame.h"
#include "LevelCell.h"

Guard::Guard(PatientGame* game, VectorXY startCoordinates)
	: Character(game, startCoordinates, game->getGuardSprite())
{
}