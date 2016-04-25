#pragma once
#include "CellEdge.h"

class CellDoor :
	public CellEdge
{
public:
	CellDoor(Directions::Direction direction, std::shared_ptr<LevelCell> cell, PatientGame* game);
	~CellDoor();

	//! This method returns whether the edge is a wall.
	/*!
	This method returns a bool indicating whether the edge is a wall.
	CellDoor is not a wall, so should return false.
	*/
	bool isWall() { return false; }

private:
	void initialiseSprite(PatientGame* game);
};
