//! Class for managing textures.
/*! 
  This class contains methods for loading and 
  rendering textures.
*/
#pragma once

class Texture
{
public:
	//! Constructor for the texture.
	/*!
	  This is the constructor for textures. It initialises
	  fileName to the given path and the texture to a null
	  pointer.
	*/
	Texture(const std::string& fileName);

	//! Destructor for the texture.
	/*!
	  This is the destructor for textures. It destroys the 
	  SDL texture if one exists.
	*/
	~Texture();

	//! Pointer to SDL texture.
	/*!
	  This is a pointer to the SDL texture, which is null until 
	  render is called.
	  The texture will be created from the sprite at the given path.
	*/
	SDL_Texture* getTexture() { return texture; }

	//! Render the texture.
	/*!
	  This method copies the texture to the renderer.
	*/
	void render(SDL_Renderer* renderer, int x, int y, int width, int height);

private:
	//! Load the texture.
	/*!
	  This private method is called when render is called, and loads the
	  image into an SDL texture.
	*/
	void loadTexture(SDL_Renderer* renderer);

	//! Private variable to store file path.
	/*!
	  This variable stores the path to the file as a string.
	  It is defined in the constructor.
	*/
	std::string imageFilename;

	//! Private pointer to SDL texture.
	/*!
	  This is a pointer to the SDL texture. The texture is null
	  until render is called.
	*/
	SDL_Texture* texture;
};
