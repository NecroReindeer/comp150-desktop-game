#include "stdafx.h"
#include "Room.h"
#include "Directions.h"
#include "PatientGame.h"

Room::Room(PatientGame* game)
	:game(game)
{
}


void Room::addCell(std::shared_ptr<LevelCell> cell)
{
	containedCells.push_back(cell);
}

void Room::addExtraDoors()
{
	if (walledCells.size() > 0)
	{
		int i = rand() % walledCells.size();
		std::shared_ptr<LevelCell> chosenCell = walledCells[i];
		std::shared_ptr<CellEdge> wall = chosenCell->getRandomWall();

		if (!wall)
		{
			walledCells.erase(walledCells.begin() + i);
			addExtraDoors();
		}
		else
		{
			Directions::Direction wallDirection = wall->getDirection();
			
			VectorXY adjacentCellCoords = chosenCell->getCoordinates() + Directions::getDirectionVector(wallDirection);

			if (game->level.containsCoordinates(adjacentCellCoords))
			{
				std::shared_ptr<LevelCell> adjacentCell = game->level.getCell(adjacentCellCoords);
				chosenCell->initialiseEdge<CellDoor>(wallDirection);
				adjacentCell->initialiseEdge<CellDoor>(Directions::getOpposite(wallDirection));
			}
			else
			{
				walledCells.erase(walledCells.begin()  + i);
				addExtraDoors();
			}
			
		}
	}
}

void Room::checkContainedCells()
{
	doorCount = 0;
	for each (std::shared_ptr<LevelCell> cell in containedCells)
	{
		
		if (cell->hasDoor())
		{
			doorCount++;
		}
		else if (cell->getWallCount() > 0)
		{
			walledCells.push_back(cell);
		}
	}

	if ((doorCount < MIN_DOORS) && (containedCells.size() > MIN_DOORS))
	{
		addExtraDoors();
		checkContainedCells();
	}
}
