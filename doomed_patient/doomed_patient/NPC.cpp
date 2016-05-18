#include "stdafx.h"
#include "NPC.h"
#include "PatientGame.h"
#include "LevelCell.h"
#include "InitialisationError.h"

NPC::NPC(PatientGame* game, VectorXY startCoordinates, Texture * sprite)
	: Character(game, startCoordinates, sprite)
{
	int random = rand() % 4;
	movementDirection = static_cast<Directions::Direction>(random);
	nextDirection = movementDirection;
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

	setNextDirection();

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
	movementDirection = nextDirection;
}


void NPC::setNextDirection()
{
	std::shared_ptr<CellEdge> currentEdge = currentCell->getEdge(movementDirection);

	if (!closeToPlayer())
	{
		while (currentEdge->isWall() || currentEdge->isDoor())
		{
			int random = rand() % 4;
			nextDirection = static_cast<Directions::Direction>(random);
			currentEdge = currentCell->getEdge(nextDirection);
		}
	}
	else
	{
		npcWall();
	}
}


void NPC::updateDirection()
{
	if (nextDirection != movementDirection)
	{
		std::shared_ptr<LevelCell> nextCell = game->level.getCell(currentCell->getCoordinates() + Directions::getDirectionVector(nextDirection));
		VectorXY currentCellCentre = currentCell->getCentre();
		// Pointer because of polymorphism
		std::shared_ptr<CellEdge> currentEdge = currentCell->getEdge(nextDirection);

		if (currentEdge->isPassage())
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
	return (euclideanDistance() < 200);
}

void NPC::followPlayer()
{
	std::vector<Directions::Direction> clearDirections = currentCell->getPassageDirections();

	double shortest = 0;
	Directions::Direction shortestDirection;

	if (clearDirections.size() < 1)
	{
		throw InitialisationError("SAD");
	}

	for each (Directions::Direction clearDirection in clearDirections)
	{
		std::shared_ptr<LevelCell> adjacentCell = game->level.getCell(currentCell->getCoordinates() + Directions::getDirectionVector(clearDirection));

		if (adjacentCell)
		{
			double distance = euclideanDistanceDirection(adjacentCell->getCoordinates());

			// If first is true, other one won't be checked
			if ((distance <= shortest) || shortest == 0)
			{
				shortest = distance;
				shortestDirection = clearDirection;
			}
		}
	}

	nextDirection = shortestDirection;
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
	VectorXY playerPosition = game->player->currentCell->getCoordinates();
	double dx = playerPosition.x - cellcoords.x;
	double dy = playerPosition.y - cellcoords.y;
	return sqrt(dx*dx + dy*dy);
}

void NPC::updateCurrentCell()
{
	currentCell = game->level.getCell(centre.convertWindowToGrid());
}


