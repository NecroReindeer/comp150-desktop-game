#pragma once


#include "GameObject.h"
class LevelCell : public GameObject
{
public:
	//! Constructor for the level cell.
	/*!
	  This is the constructor for the level cells.
	  It takes a pointer to the game and an x and y
	  position. The constructor sets up the cell's 
	  window position based on its xy grid coordinates.
	*/
	LevelCell(PatientGame* game, int x, int y);

	//! Destructor for the level cell.
	/*!
	*/
	~LevelCell();


private:
	//! Cell's x position.
	/*!
	  This integer represents the cell's x 
	  coordinate on the level grid.
	*/
	int gridPositionX;

	//! Cell's y position.
	/*!
	This integer represents the cell's y
	coordinate on the level grid.
	*/
	int gridPositionY;
};

