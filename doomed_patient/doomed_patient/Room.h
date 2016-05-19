//! Class for managing rooms.
/*!
  This class manages the rooms of the level, including
  storing what type of room it is, how many doors it has, 
  and which cells are contained within it.
*/

#pragma once
#include "LevelCell.h"


class Room
{
public:
	Room(PatientGame* game);

	//! Whether the room is a corridor or not.
	/*!
	  This bool indicates whether the room is a corridor 
	  or not. If it is true, the room is a corridor.
	*/
	bool corridor;

	//! Return the list of contained cells.
	/*!
	  This getter returns the vector of pointers to
	  cells contained in the room.
	*/
	std::vector<std::shared_ptr<LevelCell>> getCells() { return containedCells; }

	//! Adds the cell to the list of contained cells
	/*!
	  Thie method adds the given pointer to a cell to the
	  containedCells.
	*/
	void addCell(std::shared_ptr<LevelCell> cell);


	//! Add additional doors to a random cell.
	/*!
	  This method replaces a random wall of a random cell
	  that doesn't already contain a door with a door.
	*/
	void addExtraDoors();

	//!
	/*!
	*/
	void checkContainedCells();

private:
	//! A vector of all cells contained in the room.
	/*!
	  This is a vector of shared pointers to all cells that
	  are contained in this room.
	*/
	std::vector<std::shared_ptr<LevelCell>> containedCells;

	//!
	/*!
	*/
	int doorCount;

	//!
	/*!
	*/
	std::vector<std::shared_ptr<LevelCell>> walledCells;

	//!
	/*!
	*/
	PatientGame* game;

	//! Minimum amount of doors that a room is allowed to have
	/*!
	  This constant represents the minimum number of doors that a
	  room must have leading from/into it, provided that the
	  room is more than MIN_DOORS big.
	*/
	const int MIN_DOORS = 3;
};

