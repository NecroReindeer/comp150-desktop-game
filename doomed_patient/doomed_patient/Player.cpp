#include "stdafx.h"
#include "Player.h"
#include "PatientGame.h"
#include "LevelCell.h"

Player::Player(PatientGame* game)
	: Character(game, VectorXY(0, Level::GRID_SIZE_Y - 1), game->getPlayerSprite()),
	speed(2)
{
}

void Player::move(Directions::Direction direction)
{
	centre += Directions::getDirectionVector(direction) * speed;
}