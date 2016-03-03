#include "stdafx.h"
#include "Level.h"


Level::Level(PatientGame* game)
	:cells(GRID_SIZE_X, std::vector<LevelCell*>(GRID_SIZE_Y, nullptr)),
	game(game)
{
}


Level::~Level()
{
	for (int x = 0; x < GRID_SIZE_X; x++)
	{
		for (int y = 0; y < GRID_SIZE_Y; y++)
		{
			delete cells[x][y];
		}
	}
}


void Level::generate()
{
	for (int x = 0; x < GRID_SIZE_X; x++)
	{
		for (int y = 0; y < GRID_SIZE_Y; y++)
		{
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
			cells[x][y]->render(renderer);
		}
	}
}