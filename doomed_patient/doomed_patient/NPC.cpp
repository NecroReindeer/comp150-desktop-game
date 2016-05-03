#include "stdafx.h"
#include "NPC.h"
#include "PatientGame.h"
#include "LevelCell.h"


NPC::NPC(PatientGame* game, VectorXY startCoordinates, Texture * sprite)
	: Character(game, startCoordinates, sprite)
{
	int random = rand() % 4;
	movementDirection = static_cast<Directions::Direction>(random);
	updateCurrentCell();
	assignedRoom = currentCell->room.lock();
}


void NPC::move(Directions::Direction direction)
{
	centre += Directions::getDirectionVector(direction) * speed;
}


void NPC::update()
{
	// Makes sure NPC's grid position is up to date
	updateCurrentCell();

	// Update direction if necessary
	updateDirection();

	move(movementDirection);
}

// Call NPC behaviour code/methods that change NPC movementDirection from this method!
void NPC::changeDirection()
{
	std::shared_ptr<CellEdge> currentEdge = currentCell->getEdge(movementDirection);


	//PUT STUFF HERE


	// Temporary for testing
	// Changes direction to a random direction until it finds one that isn't a wall
	while (currentEdge->isWall())
	{
		int random = rand() % 4;
		movementDirection = static_cast<Directions::Direction>(random);
		currentEdge = currentCell->getEdge(movementDirection);
	}
}


void NPC::updateDirection()
{
	VectorXY currentCellCentre = currentCell->getCentre();
	// Pointer because of polymorphism
	std::shared_ptr<CellEdge> currentEdge = currentCell->getEdge(movementDirection);

	// NPC needs to change direction if there is a wall
	if (currentEdge->isWall())
	{
		// Check that the NPC is past the centre of its cell, relative
		// to its movement direction
		switch (movementDirection)
		{
		case Directions::Direction::NORTH:
			if (centre.y <= currentCellCentre.y)
			{
				centre.y = currentCellCentre.y;
				changeDirection();
			}
			break;
		case Directions::Direction::EAST:
			if (centre.x >= currentCellCentre.x)
			{
				centre.x = currentCellCentre.x;
				changeDirection();
			}
			break;
		case Directions::Direction::SOUTH:
			if (centre.y >= currentCellCentre.y)
			{
				centre.y = currentCellCentre.y;
				changeDirection();
			}
			break;
		case Directions::Direction::WEST:
			if (centre.x <= currentCellCentre.x)
			{
				centre.x = currentCellCentre.x;
				changeDirection();
			}
			break;
		}
	}
}


void NPC::updateCurrentCell()
{
	currentCell = game->level.getCell(centre.convertWindowToGrid());
}


