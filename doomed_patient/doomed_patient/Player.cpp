#include "stdafx.h"
#include "Player.h"
#include "PatientGame.h"
#include "LevelCell.h"

Player::Player(PatientGame* game, VectorXY startCoordinates)
	: Character(game, startCoordinates, game->getPlayerSprite()),
	speed(2)
{
	currentCell = game->level.getCell(VectorXY(0, 0));
	centre = currentCell->getCentre();
}

void Player::move(Directions::Direction direction)
{
	
	movementCount++;
	if (movementCount >= movementDelay)
	{

		// Put collision detection here

		if (currentCell->getEdge(direction)->isWall())
		{
			return;
		}
		currentCell = game->level.getCell(currentCell->getCoordinates() + Directions::getDirectionVector(direction));
		centre = currentCell->getCentre();
		
		movementCount = 0;
	
	}
	//centre += Directions::getDirectionVector(direction) * speed;
}