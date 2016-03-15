//! Class for the Guards.
/*!
This is a class for handling the Guards
and storing any unique data.
It inherits from th GameObject class
for any general data.
*/
#pragma once
#include "Character.h"

class LevelCell;

class Guard : public Character
{
public:
	//!Constructor for the Guard
	/*!
	  The constructor takes a pointer to the game and a shared
	  pointer to the cell that it should start in.
	  It calls through to the constructor for the base class,
	  Character, and passes its sprite in.
	*/
	Guard(PatientGame* game, std::shared_ptr<LevelCell>cell);
};

