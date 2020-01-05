#pragma once
#include "SDL.h"

class Spritesheet {
private:
	SDL_Rect m_clip;
	SDL_Surface* m_spritesheet_image;
public:
	Spritesheet(char const* path, int row, int column);
	~Spritesheet();

	void selectSprite(int x, int y);
	void drawSprite(SDL_Surface* window_surface, SDL_Rect* position);
};