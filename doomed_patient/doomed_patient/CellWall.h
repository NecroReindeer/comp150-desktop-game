#pragma once
#include "CellEdge.h"
#include "Directions.h"
#include "Texture.h"
#include "PatientGame.h"

class CellWall :
	public CellEdge
{
public:
	CellWall(Directions::Direction direction, LevelCell* cell, PatientGame* game);
	~CellWall();

	void render(SDL_Renderer* renderer);

private:
	void initialiseWallSprite(PatientGame* game);
	void initialiseCentre();
	Texture* wallSprite;
};

