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
	Player(PatientGame* game, VectorXY startCoordinates);

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

	//! Cell Position of the Player.
	/*!
	This should be made private later on. Pointer to the cell that the player
	currently occupies.
	*/
	std::shared_ptr<LevelCell> currentCell;

	//!Resets the Player position.
	/*!
	This method restarts the player when an NPC
	collides with the Player.
	*/
	void resetPosition();

	//!Changes the Direction of the Sprite.
	/*!
	This method changes the direction that the sprite
	is faceing depending on which direction it is moving.
	*/
	void changeSpriteDirection(Directions::Direction movementDirection);

protected:

	//!Movement direction of the Player.
	/*!
	This will change the direction of
	the Player.
	*/
	Directions::Direction movementDirection;

private:

	int movementCount = 0;

	static const int movementDelay = 10;

};