//! Class for the exit.
/*!
  This class is for the exit. It inherits
  from GameObject and all of the methods are
  implemented there. It has no unique functions.
*/

#pragma once
#include "GameObject.h"

class Exit :
	public GameObject
{
public:
	//! Constructor for the exit.
	/*!
	  This is the constructor for the exit.
	  It sets the sprite for the exit and converts the
	  grid coordinates of the exit into the position of
	  its centre on the window, for rendering.
	*/
	Exit(PatientGame* game, VectorXY gridCoordinates);
};

