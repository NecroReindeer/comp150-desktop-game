#pragma once


class LevelCell;

class Room
{
public:
	Room();

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

private:
	//! A vector of all cells contained in the room.
	/*!
	  This is a vector of shared pointers to all cells that
	  are contained in this room.
	*/
	std::vector<std::shared_ptr<LevelCell>> containedCells;

	int doorCount;
};

