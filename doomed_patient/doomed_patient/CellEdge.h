#pragma once
#include "Directions.h"
#include "Texture.h"

class LevelCell;
class PatientGame;

class CellEdge
{
public:
	CellEdge(Directions::Direction direction, std::shared_ptr<LevelCell> cell);
	~CellEdge();

	void render(SDL_Renderer* renderer);

protected:
	Directions::Direction direction;
	std::weak_ptr<LevelCell> containingCell;

	int centreX;
	int centreY;

	Texture* sprite;

	void initialisePosition();

private:
	virtual void initialiseSprite(PatientGame* game) = 0;

};

