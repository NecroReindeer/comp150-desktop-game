//! Class for the Doctors.
/*!
This is a class for handling the doctors 
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

class Doctor : public NPC
{
public:

	//!Constructor for the Guard
	/*!
	The constructor takes a pointer to the game and its
	starting grid coordinates.
	It calls through to the constructor for the base class,
	Character, and passes its sprite in.
	*/
	Doctor(PatientGame* game, VectorXY startCoordinates);

	//!Changes the Direction of the Sprite.
	/*!
	This method changes the direction that the sprite
	is faceing depending on which direction it is moving.
	*/
	void changeSpriteDirection();
};

