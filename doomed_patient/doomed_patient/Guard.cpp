#include "stdafx.h"
#include "Guard.h"
#include "PatientGame.h"
#include "LevelCell.h"

Guard::Guard(PatientGame* game, std::shared_ptr<LevelCell> cell)
	: Character(game, cell, game->getGuardSprite())
{
}