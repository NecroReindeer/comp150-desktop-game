#include "stdafx.h"
#include "Player.h"
#include "PatientGame.h"
#include "LevelCell.h"
#include "Character.h"

Player::Player(PatientGame* game)
	: Character(game, VectorXY(0, Level::GRID_SIZE_Y - 1), game->getPlayerSprite())

{
	speed = 2;
}
