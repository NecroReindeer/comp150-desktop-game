#include "stdafx.h"
#include "Guard.h"
#include "PatientGame.h"
#include "LevelCell.h"

Guard::Guard(PatientGame* game, VectorXY startCoordinates)
	: NPC(game, startCoordinates, game->getGuardSprite())
{
}
void Guard::move(Directions::Direction direction)
{
	centre += Directions::getDirectionVector(direction) * speed;
}