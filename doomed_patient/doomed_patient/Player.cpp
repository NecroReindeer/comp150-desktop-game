#include "stdafx.h"
#include "Player.h"
#include "PatientGame.h"
#include "LevelCell.h"

Player::Player(PatientGame* game, VectorXY gridCoordinates)
//!This is to get the texture for the Doctor
/*!It inherits this from PatientGame.cpp
which then inherits from textures.h
*/
	: GameObject(game, game->getPlayerSprite()),
	speed(2)
{
	// Calculate the window position from the grid position
	centre = gridCoordinates.convertGridToWindow();
}

void Player::move(Directions::Direction direction)
{
	centre += Directions::getDirectionVector(direction) * speed;
}