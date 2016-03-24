#include "stdafx.h"
#include "Player.h"
#include "PatientGame.h"
#include "LevelCell.h"

Player::Player(PatientGame* game, VectorXY startCoordinates)
	: Character(game, startCoordinates, game->getPlayerSprite()),
	speed(2)
{
}

void Player::move(Directions::Direction direction)
{
	centre += Directions::getDirectionVector(direction) * speed;
}