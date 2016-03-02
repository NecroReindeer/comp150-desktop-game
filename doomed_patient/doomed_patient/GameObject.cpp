#include "stdafx.h"
#include "GameObject.h"
#include "PatientGame.h"

GameObject::GameObject(PatientGame* game, Texture* sprite)
	: game(game), objectSprite(sprite)
{
	// Get the sprite size
	SDL_QueryTexture(sprite->getTexture(), nullptr, nullptr, &spriteSizeX, &spriteSizeY);
}

GameObject::~GameObject()
{
}

void GameObject::render(SDL_Renderer* renderer)
{
	// Render the game object
	objectSprite->render(renderer, centreX, centreY, spriteSizeX, spriteSizeX);
}