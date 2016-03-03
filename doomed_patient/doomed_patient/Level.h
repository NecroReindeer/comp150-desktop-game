//! Class for the level.
/*!
  This class stores data about the level and
  manages the level generation process.
*/

#pragma once
#include "LevelCell.h"

class Level
{
public:
	//! Constructor for the level.
	/*!
	  This is the constructor for the level. It takes a pointer
	  to the game to initialise that field, and also initialises the
	  vector of cells to contain nullptr.
	*/
	Level(PatientGame* game);

	//! Destructor for the level.
	/*!
	  The destructor deletes the cells that the cells
	  vector points to.
	*/
	~Level();

	//! Width of the level.
	/*!
	  This static member represents the width of
	  the level in grid squares as an integer.
	*/
	static const int GRID_SIZE_X = 15;

	//! Height of the level.
	/*!
	This static member represents the height of
	the level in grid squares as an integer.
	*/
	static const int GRID_SIZE_Y = 8;

	//! Generates the level.
	/*!
	  This method begins the level generation process.
	*/
	void generate();

	//! Render the level.
	/*!
	  This method renders the cells in the level.
	*/
	void render(SDL_Renderer* renderer);


private:
	//! Vector that holds pointers to the level's cells.
	/*!
	  This private 2d vector holds pointers to the level's
	  cells. The cells are instantiated and added to the
	  vector when generate is called.
	*/
	std::vector<std::vector<LevelCell*>> cells;

	//! Pointer to the game
	/*!
	  This is a pointer to the game, that is used to pass
	  to the generated cells so that they can access their
	  sprite.
	*/
	PatientGame* game;
};

