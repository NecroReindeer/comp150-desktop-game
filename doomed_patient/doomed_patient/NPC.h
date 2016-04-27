//! Class for the Guards.
/*!
This is a class for handling the Guards
and storing any unique data.
It inherits from th GameObject class
for any general data.
*/
#pragma once
#include "Character.h"
#include "VectorXY.h"
#include "Directions.h"
#include "LevelCell.h"

class LevelCell;

class NPC : public Character
{
public:
	//!Constructor for the Guard
	/*!
	The constructor takes a pointer to the game and its
	starting grid coordinates.
	It calls through to the constructor for the base class,
	Character, and passes its sprite in.
	*/
	NPC(PatientGame* game, VectorXY startCoordinates, Texture* sprite);

	//! Moves the player.
	/*!
	This method moves the player in the specified
	direction at the player's speed.
	*/
	void move(Directions::Direction direction);

	virtual void update(LevelCell::Passable passable);

private:
	Directions::Direction movementDirection;
};
