#pragma once
#include "GameObject.h"
#include "VectorXY.h"
#include "LevelCell.h"

class Character :
	public GameObject
{
public:
	//! Constructor for the Character.
	/*!
	  This is the constructor for the Character
	  It takes a pointer to the game, starting cell, and 
	  sprite, then calls through to the base class
	  GameObject as well as setting the centreX and centreY
	  according to the given cell.
	*/
	Character(PatientGame* game, std::shared_ptr<LevelCell> cell, Texture* sprite);

	//! Return the starting position of the character.
	/*!
	  This getter returns the starting position of the
	  character as a GridCoordinate.
	*/
	VectorXY getStartCoordinates() { return startCoordinates; }

private:
	//! Starting position for the Character
	/*!
	This is the coordinates of the cell in the grid the character
	will start in as a GridCoordinate.
	*/
	VectorXY startCoordinates;
};

