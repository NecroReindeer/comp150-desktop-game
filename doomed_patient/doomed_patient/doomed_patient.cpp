// doomed_patient.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "doomed_patient.h"
#include "PatientGame.h"
#include "InitialisationError.h"

int main(int argc, char* args[])
{
	try
	{
		PatientGame game;
		game.run();
	}
	// Throw an error if initialisation failed for any reason
	catch (InitialisationError &err)
	{
		MessageBoxA(NULL, err.what(), "Initialisation error", MB_OK | MB_ICONERROR);
		return 1;
	}

	return 0;
}