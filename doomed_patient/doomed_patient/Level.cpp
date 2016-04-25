#include "stdafx.h"
#include "Level.h"
#include "Directions.h"
#include "LevelCell.h"
#include "Room.h"
#include "Exit.h"
#include "Guard.h"
#include "Doctor.h"
#include "Player.h"

class CellWall;
class CellPassage;
class CellDoor;

const VectorXY Level::PLAYER_START(0, Level::GRID_SIZE_Y - 1);

Level::Level(PatientGame* game)
	:cells(GRID_SIZE_X, std::vector<std::shared_ptr<LevelCell>>(GRID_SIZE_Y, nullptr)),		// Initialise vector to correct size
	game(game)
{
}


Level::~Level()
{
	
}
 

bool Level::containsCoordinates(VectorXY coordinates)
{
	// Check if given coordinates are within the level size
	return (0 <= coordinates.x && coordinates.x < GRID_SIZE_X && 0 <= coordinates.y && coordinates.y < GRID_SIZE_Y);
}


std::shared_ptr<LevelCell> Level::getCell(VectorXY coordinates)
{
	return cells[coordinates.x][coordinates.y];
}


std::shared_ptr<Room> Level::createRoom()
{
	// Create a room and add a pointer to it to the vector of rooms
	std::shared_ptr<Room> room = std::make_shared<Room>();
	rooms.push_back(room);
	return room;
}

bool Level::positionOccupied(VectorXY coordinates)
{
	for each (std::shared_ptr<Character> npc in characters)
	{
		if (coordinates == npc->getStartCoordinates())
		{
			return true;
		}
	}
	return false;
}


template<typename CharacterType>
std::shared_ptr<CharacterType> Level::createCharacter(VectorXY startCoordinates)
{
	std::shared_ptr<CharacterType> character = std::make_shared<CharacterType>(game, startCoordinates);
	characters.push_back(character);
	return character;
}


void Level::generateCells(std::vector<std::shared_ptr<LevelCell>>& activeCells)
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

		// If there isn't a cell in the visted coordinates, create the cell and a passage
		if (!nextCell)
		{
			// Decide if the passaage will be a door by picking random number between 0 and 1
			double randomNumber = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
			bool isDoor = (randomNumber < DOOR_PROBABILITY) ? true : false;

			// nextCell is in a new room if there is a door, otherwise it's in the same room
			if (isDoor)
			{
				currentCell->initialiseEdge<CellDoor>(randomDirection);
				nextCell = createCell(nextCellCoordinates, createRoom());
				nextCell->initialiseEdge<CellDoor>(Directions::getOpposite(randomDirection));

			}
			else
			{
				currentCell->initialiseEdge<CellPassage>(randomDirection);
				nextCell = createCell(nextCellCoordinates, currentCell->room);
				nextCell->initialiseEdge<CellPassage>(Directions::getOpposite(randomDirection));
			}

			// Add new cell to list of active cells
			activeCells.push_back(nextCell);
		}
		// If a cell already exists and it's in the same room, create a passage
		else if (currentCell->room == nextCell->room)
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
	// If the current cell is at the edge of the level, create a wall
	else
	{
		currentCell->initialiseEdge<CellWall>(randomDirection);
	}
}


void Level::placeExit()
{
	// Get random 0 or 1. Edge is on right if not on top
	bool exitOnTopEdge = rand() % 2;

	VectorXY exitCoords;
    
	if (exitOnTopEdge)
	{
		exitCoords.x = rand() % GRID_SIZE_X;
		exitCoords.y = 0;
	}
	else
	{
		exitCoords.x = GRID_SIZE_X - 1;
		exitCoords.y = rand() % GRID_SIZE_Y;
	}

	exit = std::make_shared<Exit>(game, exitCoords);
}

void Level::clearLevel()
{
	// Clear all the cells from the vector
	cells.clear();
	for (int x = 0; x < GRID_SIZE_X; x++)
	{
		// Add nullptrs to all the spaces where cells would be
		cells.push_back(std::vector<std::shared_ptr<LevelCell>>(GRID_SIZE_Y, nullptr));
	}

	characters.clear();
}

void Level::generateMaze()
{
	clearLevel();

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
	
	placeExit();

	player = createCharacter<Player>(PLAYER_START);

	// Temporary literal 5 for testing
	for (int i = 0; i < 5; i++)
	{
		createCharacter<Guard>(getUnoccupiedRandomCoords());
		createCharacter<Doctor>(getUnoccupiedRandomCoords());
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

	exit->render(renderer);

	for (int i = 0; i < characters.size(); i++)
	{
		characters[i]->render(renderer);
	}
}


std::shared_ptr<LevelCell> Level::createCell(VectorXY coordinates, std::shared_ptr<Room> room)
{
	cells[coordinates.x][coordinates.y] = std::make_shared<LevelCell>(game, coordinates, room);
	return cells[coordinates.x][coordinates.y];
}


VectorXY Level::getUnoccupiedRandomCoords()
{
	bool positionIsValid = false;

	VectorXY unoccupiedCoordinates(rand() % GRID_SIZE_X, rand() % GRID_SIZE_Y);

	if (!characters.empty())
	{	
		// Ensure that 2 NPCs aren't spawned in the same place
		while (positionOccupied(unoccupiedCoordinates))
		{
			unoccupiedCoordinates.x = rand() % GRID_SIZE_X;
			unoccupiedCoordinates.y = rand() % GRID_SIZE_Y;
		}
	}

	return unoccupiedCoordinates;
}

VectorXY Level::getRandomCoordinates()
{
	VectorXY coordinates;
	coordinates.x = rand() % Level::GRID_SIZE_X;
	coordinates.y = rand() % Level::GRID_SIZE_Y;
	return coordinates;
}