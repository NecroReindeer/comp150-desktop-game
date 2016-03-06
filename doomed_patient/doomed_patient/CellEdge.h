#pragma once
#include "Directions.h"
#include "Texture.h"

class LevelCell;
class PatientGame;

class CellEdge
{
public:
	CellEdge(Directions::Direction direction, LevelCell* cell);
	~CellEdge();

	void render(SDL_Renderer* renderer);

protected:
	Directions::Direction direction;
	LevelCell* cell;

	int centreX;
	int centreY;

	Texture* sprite;

	void initialisePosition();

private:
	virtual void initialiseSprite(PatientGame* game) = 0;

};

