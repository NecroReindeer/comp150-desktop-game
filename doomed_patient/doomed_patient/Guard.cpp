#include "stdafx.h"
#include "Guard.h"
#include "PatientGame.h"

Guard::Guard(PatientGame* game)
//!This is to get the texture for the Guard
/*!It inherits this from PatientGame.cpp
which then inherits from textures.h
*/
	: GameObject(game, game->getGuardSprite())
	
{
}


Guard::~Guard()
{
}
