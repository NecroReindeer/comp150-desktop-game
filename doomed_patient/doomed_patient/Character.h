#pragma once
#include "GameObject.h"
#include "GridCoordinate.h"
#include "LevelCell.h"

class Character :
	public GameObject
{
public:
	Character(PatientGame* game, std::shared_ptr<LevelCell> cell, Texture* sprite);
	~Character();

	GridCoordinate getStartCoordinates() { return startCoordinates; }

private:
	GridCoordinate startCoordinates;
};

