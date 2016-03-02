#include "stdafx.h"
#include "PatientGame.h"
#include "InitialisationError.h"


PatientGame::PatientGame()
{

	// Initialise SDL video system
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw InitialisationError("SDL_Init failed");
	}

	// Create window for the game
	window = SDL_CreateWindow("The Doomed Patient", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	// Check if window was successfully created
	if (window == nullptr)
	{
		throw InitialisationError("SDL_CreateWindow failed");
	}

	// Create renderer for the game
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	// Check if renderer was successfully created
	if (renderer == nullptr)
	{
		throw InitialisationError("SDL_CreateRenderer failed");
	}
}


PatientGame::~PatientGame()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


void PatientGame::run()
{
	running = true;

	// Main game loop
	while (running)
	{
		handleEvents();
		update();
		render();
	}
}


// Handle events such as quitting and player input here
void PatientGame::handleEvents()
{
	SDL_Event ev;
	if (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
		// Close the game when user quits
		case SDL_QUIT:
			running = false;
			break;

		default:
			break;
		}
	} 
}


// Game updates that need to happen every frame go here
void PatientGame::update()
{

}


// Render objects and draw them to the screen here
void PatientGame::render()
{
	// Clear the screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	//Render game objects here

	// Present the newly rendered screen
	SDL_RenderPresent(renderer);
}