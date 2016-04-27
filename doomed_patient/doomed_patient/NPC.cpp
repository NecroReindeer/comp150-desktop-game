#include "stdafx.h"
#include "NPC.h"
#include "PatientGame.h"
#include "LevelCell.h"


NPC::NPC(PatientGame* game, VectorXY startCoordinates, Texture * sprite)
	: Character(game, startCoordinates, sprite)
{
	int random = rand() % 4;
	movementDirection = static_cast<Directions::Direction>(random);
}
void NPC::move(Directions::Direction direction)
{
	centre += Directions::getDirectionVector(direction) * speed;
}
void NPC::update(LevelCell::Passable blocked)
{
	//Checking for passable directions and updateing direction

	//North -> South

	if (movementDirection == Directions::Direction::NORTH && !blocked.NORTH)
	{ 
		move(movementDirection);
	}
	else if (movementDirection == Directions::Direction::NORTH && blocked.NORTH && !blocked.SOUTH)
	{
		movementDirection = Directions::Direction::SOUTH;
		move(movementDirection);
	}

	// East -> West

	if (movementDirection == Directions::Direction::EAST && !blocked.EAST)
	{
		move(movementDirection);
	}
	else if (movementDirection == Directions::Direction::EAST && blocked.EAST && !blocked.WEST)
	{
		movementDirection = Directions::Direction::WEST;
		move(movementDirection);
	}

	// South -> North

	if (movementDirection == Directions::Direction::SOUTH && !blocked.SOUTH)
	{
		move(movementDirection);
	}
	else if (movementDirection == Directions::Direction::SOUTH && blocked.SOUTH && !blocked.NORTH)
	{
		movementDirection = Directions::Direction::NORTH;
		move(movementDirection);
	}

	// West -> East

	if (movementDirection == Directions::Direction::WEST && !blocked.WEST)
	{
		move(movementDirection);
	}
	else if (movementDirection == Directions::Direction::WEST && blocked.WEST && !blocked.EAST)
	{
		movementDirection = Directions::Direction::EAST;
		move(movementDirection);
	}



//	if (!blocked.NORTH && blocked.EAST && blocked.SOUTH && blocked.WEST)
//	{
//		move(Directions::Direction::NORTH);
//	}
//	else if (movementDirection == Directions::Direction::WEST && blocked.WEST && !blocked.EAST)
//	{
//		movementDirection = Directions::Direction::EAST;
//		move(movementDirection);
//	}



//	if (movementDirection == Directions::Direction:: && blocked.NORTH && !blocked.EAST && blocked.SOUTH && blocked.WEST)
//	{
//		move(Directions::Direction::EAST);
//	}
//
//
//
//	if (blocked.NORTH && blocked.EAST && !blocked.SOUTH && blocked.WEST)
//	{
//		move(Directions::Direction::SOUTH);
//	}
//
//
//
//	if (blocked.NORTH && blocked.EAST && blocked.SOUTH && !blocked.WEST)
//	{
//		move(Directions::Direction::WEST);
//	}
}