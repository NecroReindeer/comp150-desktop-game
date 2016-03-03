#include "stdafx.h"
#include "GameObject.h"
#include "PatientGame.h"
#include "InitialisationError.h"

GameObject::GameObject(PatientGame* game, Texture* sprite)
	: game(game), objectSprite(sprite)
{
	// Get the sprite size
	SDL_Surface* image;
	image = IMG_Load(objectSprite->getImageFileName().c_str());

	if (!image)
	{
		throw InitialisationError("IMG_Load failed.");
	}

	spriteSizeX = image->w;
	spriteSizeY = image->h;
}

GameObject::~GameObject()
{
}

void GameObject::render(SDL_Renderer* renderer)
{
	// Render the game object
	objectSprite->render(renderer, centreX, centreY, spriteSizeX, spriteSizeY);
}