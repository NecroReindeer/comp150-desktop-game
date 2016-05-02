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
#include "NPC.h"

class LevelCell;

class Guard : public NPC
{
public:
	//!Constructor for the Guard
	/*!
	  The constructor takes a pointer to the game and its
	  starting grid coordinates.
	  It calls through to the constructor for the base class,
	  Character, and passes its sprite in.
	*/
	Guard(PatientGame* game, VectorXY startCoordinates);

	//! Moves the player.
	/*!
	This method moves the player in the specified
	direction at the player's speed.
	*/
	void move(Directions::Direction direction);

};

