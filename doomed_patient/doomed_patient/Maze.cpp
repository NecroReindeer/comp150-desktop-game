#include "stdafx.h"
#include "Maze.h"
#include "Room.h"
#include "LevelCell.h"
#include "PatientGame.h"

Maze::Maze(PatientGame* game)
	:cells(Level::GRID_SIZE_X, std::vector<std::shared_ptr<LevelCell>>(Level::GRID_SIZE_Y, nullptr)),		// Initialise vector to correct size
	game(game)
{
}


Maze::~Maze()
{
}

void Maze::clearMaze()
{
	// Clear all the cells from the vector
	cells.clear();
	for (int x = 0; x < Level::GRID_SIZE_X; x++)
	{
		// Add nullptrs to all the spaces where cells would be
		cells.push_back(std::vector<std::shared_ptr<LevelCell>>(Level::GRID_SIZE_Y, nullptr));
	}
}

void Maze::generateCells(std::vector<std::shared_ptr<LevelCell>>& activeCells)
{
	// Last index. Can be changed (first, middle, or random) to give different results
	int currentIndex = activeCells.size() - 1;
	std::shared_ptr<LevelCell> currentCell = activeCells[currentIndex];

	// Delete the cell from the list of active cell if all edges have been set
	if (currentCell->allEdgesInitialised())
	{
		activeCells.erase(activeCells.begin() + currentIndex);
		return;
	}

	// Get a random direction that doesn't yet have an edge set
	Directions::Direction randomDirection = currentCell->getRandomUninitialisedDirection();

	// Calculate the next coordinates to be visited
	VectorXY nextCellCoordinates = currentCell->getCoordinates() + Directions::getDirectionVector(randomDirection);

	if (containsCoordinates(nextCellCoordinates))
	{
		std::shared_ptr<LevelCell> nextCell = getCell(nextCellCoordinates);
		std::shared_ptr<Room> currentCellRoom = currentCell->room.lock();

		// If there isn't a cell in the visted coordinates, create the cell and a passage
		if (!nextCell)
		{
			bool isDoor;


			// Decide if the passage will be a door by picking random number between 0 and 1
			double randomNumber = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
			isDoor = (randomNumber < DOOR_PROBABILITY) ? true : false;

			if (currentIndex > 0)
			{
				bool doorRequired = assignDoor(currentCellRoom, currentCell, nextCellCoordinates, activeCells[currentIndex - 1]);
				if (doorRequired)
				{
					isDoor = doorRequired;
				}
			}

			if (currentCellRoom->getCells().size() < MIN_ROOM_SIZE)
			{
				isDoor = false;
			}
			else if (currentCellRoom->getCells().size() >= MAX_ROOM_SIZE)
			{
				isDoor = true;
			}


			// nextCell is in a new room if there is a door, otherwise it's in the same room
			if (isDoor)
			{
				currentCell->initialiseEdge<CellDoor>(randomDirection);
				nextCell = createCell(nextCellCoordinates, createRoom(currentCellRoom));
				nextCell->initialiseEdge<CellDoor>(Directions::getOpposite(randomDirection));
			}
			else
			{
				currentCell->initialiseEdge<CellPassage>(randomDirection);
				nextCell = createCell(nextCellCoordinates, currentCellRoom);
				nextCell->initialiseEdge<CellPassage>(Directions::getOpposite(randomDirection));
			}

			// Add new cell to list of active cells
			activeCells.push_back(nextCell);
		}
		// If a cell already exists and it's in the same room, create a passage
		else if (nextCell)
		{
			std::shared_ptr<Room> nextCellRoom = nextCell->room.lock();

			if (currentCellRoom == nextCellRoom)
			{
				currentCell->initialiseEdge<CellPassage>(randomDirection);
				nextCell->initialiseEdge<CellPassage>(Directions::getOpposite(randomDirection));
			}
			// If a cell already exists and isn't in the same room, create a wall
			else
			{
				currentCell->initialiseEdge<CellWall>(randomDirection);
				nextCell->initialiseEdge<CellWall>(Directions::getOpposite(randomDirection));
			}
		}
	}
	// If the current cell is at the edge of the level, create a wall
	else
	{
		currentCell->initialiseEdge<CellWall>(randomDirection);
	}
}


bool Maze::assignDoor(std::shared_ptr<Room> currentRoom, std::shared_ptr<LevelCell> currentCell, VectorXY nextCellCoordinates, std::shared_ptr<LevelCell> previousCell)
{
	bool isDoor = false;
	std::shared_ptr<Room> prevCellRoom = previousCell->room.lock();


	if (currentRoom->corridor && prevCellRoom->corridor)
	{
		if (currentCell->getCoordinates().x == previousCell->getCoordinates().x)
		{
			if (nextCellCoordinates.x != currentCell->getCoordinates().x)
			{
				isDoor = true;
			}
		}
		else if (currentCell->getCoordinates().y == previousCell->getCoordinates().y)
		{
			if (nextCellCoordinates.y != currentCell->getCoordinates().y)
			{
				isDoor = true;
			}
		}
	}

	return isDoor;
}


void Maze::generate()
{
	// Randomly choose position to start from and add it to activeCells
	std::vector<std::shared_ptr<LevelCell>> activeCells;
	std::shared_ptr<Room> room = createRoom();
	VectorXY firstCellCoordinates = getRandomCoordinates();
	std::shared_ptr<LevelCell> firstCell = createCell(firstCellCoordinates, room);
	activeCells.push_back(firstCell);

	while (activeCells.size() > 0)
	{
		generateCells(activeCells);

		// For testing
		//render(renderer);
		//SDL_RenderPresent(renderer);
	}
}


std::shared_ptr<Room> Maze::createRoom(std::shared_ptr<Room> cameFrom)
{
	std::shared_ptr<Room> room = createRoom();
	if (cameFrom->corridor)
	{
		room->corridor = false;
	}
	return room;
}


std::shared_ptr<Room> Maze::createRoom()
{
	// Create a room and add a pointer to it to the vector of rooms
	std::shared_ptr<Room> room = std::make_shared<Room>();
	rooms.push_back(room);
	return room;
}


std::shared_ptr<LevelCell> Maze::createCell(VectorXY coordinates, std::shared_ptr<Room> room)
{
	cells[coordinates.x][coordinates.y] = std::make_shared<LevelCell>(game, coordinates);

	// IF statement temporary for testing! visualises corridors
	if (room->corridor)
	{
		cells[coordinates.x][coordinates.y] = nullptr;
		cells[coordinates.x][coordinates.y] = std::make_shared<LevelCell>(game, coordinates, game->getCorridorSprite());
	}

	cells[coordinates.x][coordinates.y]->assignRoom(room);
	return cells[coordinates.x][coordinates.y];
}

std::shared_ptr<LevelCell> Maze::getCell(VectorXY coordinates)
{
	return cells[coordinates.x][coordinates.y];
}


VectorXY Maze::getRandomCoordinates()
{
	VectorXY coordinates;
	coordinates.x = rand() % Level::GRID_SIZE_X;
	coordinates.y = rand() % Level::GRID_SIZE_Y;
	return coordinates;
}

bool Maze::containsCoordinates(VectorXY coordinates)
{
	// Check if given coordinates are within the level size
	return (0 <= coordinates.x && coordinates.x < Level::GRID_SIZE_X && 0 <= coordinates.y && coordinates.y < Level::GRID_SIZE_Y);
}

void Maze::render(SDL_Renderer* renderer)
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
