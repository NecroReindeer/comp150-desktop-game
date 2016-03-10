//! Class for the Player.
/*!
This is a class for handling the Players
and storing any unique data.
It inherits from th GameObject class
for any general data.
*/
#pragma once

#include "GameObject.h"

class LevelCell;

class Player : public GameObject
{
public:
	//!Constructor for the Player
	/*!
	*/
	Player(PatientGame* game, std::shared_ptr<LevelCell>cell);

	//!Destuctor for the Player
	/*!
	*/
	~Player();


};