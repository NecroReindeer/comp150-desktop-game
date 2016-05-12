#include "stdafx.h"
#include "Guard.h"
#include "PatientGame.h"
#include "LevelCell.h"
#include "Player.h"

Guard::Guard(PatientGame* game, VectorXY startCoordinates)
	: NPC(game, startCoordinates, game->getGuardSprite())
{
}
void Guard::move(Directions::Direction direction)
{
	centre += Directions::getDirectionVector(direction) * speed;

	VectorXY playerPosition=game->player->getCentre();
	double distance = sqrt(pow(centre.x - playerPosition.x, 2) + pow(centre.y - playerPosition.y, 2));
	if (distance < 4)
	{
		
	}

}