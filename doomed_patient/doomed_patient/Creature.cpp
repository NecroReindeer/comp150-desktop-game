#include "stdafx.h"
#include "Creature.h"
#include "PatientGame.h"

Creature::Creature(PatientGame* game)
	: GameObject(game, game->getCreatureSprite())
{
	centreX = 450;
	centreY = 200;
}


Creature::~Creature()
{
}
