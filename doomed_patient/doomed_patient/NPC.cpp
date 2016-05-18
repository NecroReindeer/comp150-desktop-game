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

	changeSpriteDirection();

	double distance = euclideanDistance();
	if (distance < 35)
	{
		game->player->resetPosition();
	}
}

// Call NPC behaviour code/methods that change NPC movementDirection from this method!
void NPC::changeDirection()
{
	std::shared_ptr<CellEdge> currentEdge = currentCell->getEdge(movementDirection);

	npcWall();
}


void NPC::updateDirection()
{
	VectorXY currentCellCentre = currentCell->getCentre();
	// Pointer because of polymorphism
	std::shared_ptr<CellEdge> currentEdge = currentCell->getEdge(movementDirection);

	// NPC needs to change direction if there is a wall
	if (currentEdge->isWall() || currentEdge->isDoor() || closeToPlayer())
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

void NPC::npcWall()
{
	if (closeToPlayer())
	{
		followPlayer();
	}
}

bool NPC::closeToPlayer()
{
	return euclideanDistance() < 200;
}

void NPC::followPlayer()
{
	std::vector<std::shared_ptr<CellEdge>>passages = currentCell->getPassages();

	double shortest = 1000000;
	Directions::Direction shortestDirection;
	for each (std::shared_ptr<CellEdge> passage in passages)
	{
		Directions::Direction clear = passage->getDirection();
		std::shared_ptr<LevelCell> adjacentCell = game->level.getCell(currentCell->getCoordinates() + Directions::getDirectionVector(clear));

		double distance = euclideanDistanceDirection(adjacentCell->getCentre());

		if (distance < shortest)
		{
			shortest = distance;
			shortestDirection = clear;
		}
	}

	movementDirection = shortestDirection;
}



double NPC::euclideanDistance()
{
	VectorXY playerPosition = game->player->getCentre();
	double dx = playerPosition.x - centre.x;
	double dy = playerPosition.y - centre.y;
	return sqrt(dx*dx + dy*dy);
}

double NPC::euclideanDistanceDirection(VectorXY cellcoords)
{
	VectorXY playerPosition = game->player->getCentre();
	double dx = playerPosition.x - cellcoords.x;
	double dy = playerPosition.y - cellcoords.y;
	return sqrt(dx*dx + dy*dy);
}

void NPC::updateCurrentCell()
{
	currentCell = game->level.getCell(centre.convertWindowToGrid());
}


