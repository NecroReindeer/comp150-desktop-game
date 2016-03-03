#include "stdafx.h"
#include "Level.h"


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


void Level::generate()
{
	for (int x = 0; x < GRID_SIZE_X; x++)
	{
		for (int y = 0; y < GRID_SIZE_Y; y++)
		{
			// Create a cell at index corresponding to its grid position
			cells[x][y] = new LevelCell(game, x, y);
		}
	}
}


void Level::render(SDL_Renderer* renderer)
{
	for (int x = 0; x < GRID_SIZE_X; x++)
	{
		for (int y = 0; y < GRID_SIZE_Y; y++)
		{
			// Render each cell
			cells[x][y]->render(renderer);
		}
	}
}