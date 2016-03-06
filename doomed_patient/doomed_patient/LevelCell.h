#pragma once
#include "GameObject.h"
#include "CellEdge.h"
#include "GridCoordinate.h"



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

	void render(SDL_Renderer* renderer);

	bool allEdgesInitialised();

	Directions::Direction getRandomUninitialisedDirection();

	static const int NUMBER_OF_SIDES = 4;

	GridCoordinate getCoordinates() { return GridCoordinate(gridPositionX, gridPositionY); }

	void createWall(Directions::Direction direction);
	void createPassage(Directions::Direction direction);

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

	CellEdge* northEdge;
	CellEdge* eastEdge;
	CellEdge* southEdge;
	CellEdge* westEdge;

	//CellEdge* edges[NUMBER_OF_SIDES];
	std::map<Directions::Direction, CellEdge*> edges;
};

