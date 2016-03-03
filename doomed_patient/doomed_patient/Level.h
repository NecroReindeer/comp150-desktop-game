//! Class for the level.
/*!
  This class stores data about the level and
  manages the level generation process.
*/

#pragma once
#include "LevelCell.h"

class Level
{
public:
	Level(PatientGame* game);
	~Level();

	static const int GRID_SIZE_X = 15;
	static const int GRID_SIZE_Y = 8;

	void generate();
	void render(SDL_Renderer* renderer);

private:
	std::vector<std::vector<LevelCell*>> cells;
	PatientGame* game;
};

