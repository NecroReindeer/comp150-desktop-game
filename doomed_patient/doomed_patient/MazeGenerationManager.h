#pragma once
#include "Directions.h"
#include "LevelCell.h"
#include "Room.h"


class MazeGenerationManager
{
public:
	MazeGenerationManager();
	~MazeGenerationManager();
	std::vector<std::shared_ptr<LevelCell>> activeCells;
	std::shared_ptr<LevelCell> currentCell;
	std::shared_ptr<LevelCell> nextCell;
	std::shared_ptr<LevelCell> previousCell;
	VectorXY nextCellCoordinates;
	Directions::Direction nextDirection;
	std::shared_ptr<Room> currentRoom;
	int currentIndex;
	VectorXY getNextCellCoordinates();
	std::shared_ptr<LevelCell> getPreviousCell();
};

