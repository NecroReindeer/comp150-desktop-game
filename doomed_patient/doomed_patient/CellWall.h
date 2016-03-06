#pragma once
#include "CellEdge.h"
#include "Directions.h"

class PatientGame;

class CellWall :
	public CellEdge
{
public:
	CellWall(Directions::Direction direction, LevelCell* cell, PatientGame* game);
	~CellWall();


private:
	void initialiseSprite(PatientGame* game);
};

