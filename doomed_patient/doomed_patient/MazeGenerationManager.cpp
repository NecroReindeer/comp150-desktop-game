#include "stdafx.h"
#include "MazeGenerationManager.h"


MazeGenerationManager::MazeGenerationManager()
{
}


MazeGenerationManager::~MazeGenerationManager()
{
}


VectorXY MazeGenerationManager::getNextCellCoordinates()
{
	return getCurrentCell()->getCoordinates() + Directions::getDirectionVector(nextDirection);
}

std::shared_ptr<LevelCell>  MazeGenerationManager::getCurrentCell()
{
	return activeCells[currentIndex];
}

std::shared_ptr<LevelCell>  MazeGenerationManager::getPreviousCell()
{
	if (activeCells.size() > 0)
	{
		return activeCells[currentIndex - 1];
	}
}

std::shared_ptr<Room>  MazeGenerationManager::getCurrentRoom()
{
	std::shared_ptr<Room> room = getCurrentCell()->room.lock();
	return room;
}

