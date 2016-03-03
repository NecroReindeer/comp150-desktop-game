#pragma once


#include "GameObject.h"
class LevelCell :
	public GameObject
{
public:
	LevelCell(PatientGame* game, int x, int y);
	~LevelCell();

private:
	int gridPositionX;
	int gridPositionY;
};

