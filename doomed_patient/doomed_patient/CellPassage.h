#pragma once
#include "CellEdge.h"

class PatientGame;

class CellPassage :
	public CellEdge
{
public:
	CellPassage(Directions::Direction direction, LevelCell* cell, PatientGame* game, bool isDoor);
	~CellPassage();


	bool isDoor;

private:
	void initialiseSprite(PatientGame* game);

};

