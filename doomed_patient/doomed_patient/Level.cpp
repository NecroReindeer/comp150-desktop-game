#include "stdafx.h"
#include "Level.h"
#include "GridCoordinate.h"
#include "Directions.h"


Level::Level(PatientGame* game)
	:cells(GRID_SIZE_X, std::vector<LevelCell*>(GRID_SIZE_Y, nullptr)),		// initialise vector to correct size
	game(game)
{
}


Level::~Level()
{
	for (int x = 0; x < GRID_SIZE_X; x++)
	{
		for (int y = 0; y < GRID_SIZE_Y; y++)
		{
			// Delete the cells created in generate if they exist
			if (cells[x][y])
			{
				delete cells[x][y];
			}
		}
	}
}

bool Level::containsCoordinates(GridCoordinate coordinates)
{
	return (0 <= coordinates.x && coordinates.x < GRID_SIZE_X && 0 <= coordinates.y && coordinates.y < GRID_SIZE_Y);
}

LevelCell* Level::getCell(GridCoordinate coordinates)
{
	return cells[coordinates.x][coordinates.y];
}

void Level::generateCells(std::vector<LevelCell*>& activeCells)
{
	int currentIndex = activeCells.size() - 1;
	LevelCell* currentCell = activeCells[currentIndex];

	if (currentCell->allEdgesInitialised())
	{
		activeCells.erase(activeCells.begin() + currentIndex);
		return;
	}

	Directions::Direction randomDirection = currentCell->getRandomUninitialisedDirection();
	GridCoordinate nextCellCoordinates = currentCell->getCoordinates() + Directions::getDirectionVector(randomDirection);

	if (containsCoordinates(nextCellCoordinates))
	{
		LevelCell* nextCell = getCell(nextCellCoordinates);
		if (!nextCell)
		{
			nextCell = createCell(nextCellCoordinates);

			double randomNumber = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
			bool isDoor = (randomNumber < DOOR_PROBABILITY) ? true : false;

			currentCell->createPassage(randomDirection, isDoor);
			nextCell->createPassage(Directions::getOpposite(randomDirection), isDoor);

			activeCells.push_back(nextCell);
		}
		else
		{
			currentCell->createWall(randomDirection);
			nextCell->createWall(Directions::getOpposite(randomDirection));
		}
	}
	else
	{
		currentCell->createWall(randomDirection);
	}
}

void Level::generateMaze()
{
	std::vector<LevelCell*> activeCells;
	GridCoordinate firstCellCoordinates = getRandomCoordinates();
	activeCells.push_back(createCell(firstCellCoordinates));

	while (activeCells.size() > 0)
	{
		generateCells(activeCells);

		// For testing
		render(renderer);
		SDL_RenderPresent(renderer);
	}

}


void Level::render(SDL_Renderer* renderer)
{
	for (int x = 0; x < GRID_SIZE_X; x++)
	{
		for (int y = 0; y < GRID_SIZE_Y; y++)
		{
			// Render each cell
			if (cells[x][y])
				cells[x][y]->render(renderer);
		}
	}
}

LevelCell* Level::createCell(GridCoordinate coordinates)
{
	cells[coordinates.x][coordinates.y] = new LevelCell(game, coordinates.x, coordinates.y);
	return cells[coordinates.x][coordinates.y];
}

GridCoordinate Level::getRandomCoordinates()
{
	GridCoordinate coordinates;
	coordinates.x = rand() % Level::GRID_SIZE_X;
	coordinates.y = rand() % Level::GRID_SIZE_Y;
	return coordinates;
}