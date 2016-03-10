#include "stdafx.h"
#include "Player.h"
#include "PatientGame.h"

Player::Player(PatientGame* game)
	: GameObject(game, game->getPlayerSprite())
{
}


Player::~Player()
{
}
