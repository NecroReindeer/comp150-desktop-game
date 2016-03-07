#include "stdafx.h"
#include "Level.h"
#include "GridCoordinate.h"
#include "Directions.h"
#include "LevelCell.h"
#include "Room.h"


Level::Level(PatientGame* game)
	:cells(GRID_SIZE_X, std::vector<LevelCell*>(GRID_SIZE_Y, nullptr)),		// Initialise vector to correct size
	game(game)
{
}


Level::~Level()
{
	// Delete the cells created in generate if they exist
	for (int x = 0; x < GRID_SIZE_X; x++)
	{
		for (int y = 0; y < GRID_SIZE_Y; y++)
		{
			if (cells[x][y])
			{
				delete cells[x][y];
			}
		}
	}

	// Delete all created rooms
	for each (Room* room in rooms)
	{
		if (room)
		{
			delete room;
		}
	}
}
 

bool Level::containsCoordinates(GridCoordinate coordinates)
{
	// Check if given coordinates are within the level size
	return (0 <= coordinates.x && coordinates.x < GRID_SIZE_X && 0 <= coordinates.y && coordinates.y < GRID_SIZE_Y);
}


LevelCell* Level::getCell(GridCoordinate coordinates)
{
	return cells[coordinates.x][coordinates.y];
}


Room* Level::createRoom()
{
	// Create a room and add a pointer to it to the vector of rooms
	Room* room = new Room;
	rooms.push_back(room);
	return room;
}


void Level::generateCells(std::vector<LevelCell*>& activeCells)
{
	// Last index. Can be changed (first, middle, or random) to give different results
	int currentIndex = activeCells.size() - 1;
	LevelCell* currentCell = activeCells[currentIndex];

	// Delete the cell from the list of active cell if all edges have been set
	if (currentCell->allEdgesInitialised())
	{
		activeCells.erase(activeCells.begin() + currentIndex);
		return;
	}

	// Get a random direction that doesn't yet have an edge set
	Directions::Direction randomDirection = currentCell->getRandomUninitialisedDirection();

	// Calculate the next coordinates to be visited
	GridCoordinate nextCellCoordinates = currentCell->getCoordinates() + Directions::getDirectionVector(randomDirection);

	if (containsCoordinates(nextCellCoordinates))
	{
		LevelCell* nextCell = getCell(nextCellCoordinates);

		// If there isn't a cell in the visted coordinates, create the cell and a passage
		if (!nextCell)
		{
			// Decide if the passaage will be a door
			double randomNumber = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
			bool isDoor = (randomNumber < DOOR_PROBABILITY) ? true : false;

			currentCell->createPassage(randomDirection, isDoor);

			// nextCell is in a new room if there is a door, otherwise it's in the same room
			if (isDoor)
			{
				nextCell = createCell(nextCellCoordinates, createRoom());
			}
			else
			{
				nextCell = createCell(nextCellCoordinates, currentCell->room);
			}

			nextCell->createPassage(Directions::getOpposite(randomDirection), isDoor);

			// Add new cell to list of active cells
			activeCells.push_back(nextCell);
		}
		// If a cell already exists and it's in the same room, create a passage
		else if (currentCell->room == nextCell->room)
		{
			currentCell->createPassage(randomDirection, false);
			nextCell->createPassage(Directions::getOpposite(randomDirection), false);
		}
		// If a cell already exists and isn't in the same room, create a wall
		else
		{
			currentCell->createWall(randomDirection);
			nextCell->createWall(Directions::getOpposite(randomDirection));
		}
	}
	// If the current cell is at the edge of the level, create a wall
	else
	{
		currentCell->createWall(randomDirection);
	}
}


void Level::generateMaze()
{
	// Randomly choose position to start from and add it to activeCells
	std::vector<LevelCell*> activeCells;
	Room* room = createRoom();
	GridCoordinate firstCellCoordinates = getRandomCoordinates();
	LevelCell* firstCell = createCell(firstCellCoordinates, room);
	activeCells.push_back(firstCell);

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
			{
				cells[x][y]->render(renderer);
			}
		}
	}
}

LevelCell* Level::createCell(GridCoordinate coordinates, Room* room)
{
	cells[coordinates.x][coordinates.y] = new LevelCell(game, coordinates.x, coordinates.y, room);
	return cells[coordinates.x][coordinates.y];
}


GridCoordinate Level::getRandomCoordinates()
{
	GridCoordinate coordinates;
	coordinates.x = rand() % Level::GRID_SIZE_X;
	coordinates.y = rand() % Level::GRID_SIZE_Y;
	return coordinates;
}