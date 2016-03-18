//! Class for the Player.
/*!
This is a class for handling the Players
and storing any unique data.
It inherits from th GameObject class
for any general data.
*/
#pragma once

#include "Character.h"
#include "Level.h"
#include "Directions.h"

class LevelCell;

class Player : public Character
{
public:
	//!Constructor for the Player
	/*!
	  The constructor for the player initialises the speed
	  and calls through to the base class constructor with
	  the player's start position.
	*/
	Player(PatientGame* game);

	//! Speed of the player.
	/*!
	  This field holds the speed that the player
	  moves. 
	*/
	int speed;

	//! Moves the player.
	/*!
	  This method moves the player in the specified
	  direction at the player's speed.
	*/
	void move(Directions::Direction direction);
};