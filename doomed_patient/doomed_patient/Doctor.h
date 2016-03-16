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

class LevelCell;

class Doctor : public Character
{
public:
	//!Constructor for the Doctor
	/*!
	  The constructor takes a pointer to the game and a shared
	  pointer to the cell that it should start in.
	  It calls through to the constructor for the base class,
	  Character, and passes its sprite in.
	*/
	Doctor(PatientGame* game, std::shared_ptr<LevelCell>cell);
};

