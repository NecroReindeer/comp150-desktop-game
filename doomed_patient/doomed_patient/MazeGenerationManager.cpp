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
	return currentCell->getCoordinates() + Directions::getDirectionVector(nextDirection);
}

std::shared_ptr<LevelCell>  MazeGenerationManager::getPreviousCell()
{
	if (activeCells.size() > 0)
	{
		return activeCells[currentIndex - 1];
	}
}
