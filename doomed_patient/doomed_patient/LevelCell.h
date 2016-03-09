#pragma once
#include "GameObject.h"
#include "CellEdge.h"
#include "GridCoordinate.h"

class Room;

class LevelCell : public GameObject, public std::enable_shared_from_this<LevelCell>		// So that this can be passed as a shared pointer
{
public:
	//! Constructor for the level cell.
	/*!
	  This is the constructor for the level cells.
	  It takes a pointer to the game and an x and y
	  position. The constructor sets up the cell's 
	  window position based on its xy grid coordinates.
	*/
	LevelCell(PatientGame* game, int x, int y, Room* room);

	void createWall(Directions::Direction direction);

	void createPassage(Directions::Direction direction, bool isDoor);

	void render(SDL_Renderer* renderer);

	bool allEdgesInitialised();

	Directions::Direction getRandomUninitialisedDirection();

	GridCoordinate getCoordinates() { return GridCoordinate(gridPositionX, gridPositionY); }

	Room* room;

	static const int NUMBER_OF_SIDES = 4;


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

	std::map<Directions::Direction, std::shared_ptr<CellEdge>> edges;
};

