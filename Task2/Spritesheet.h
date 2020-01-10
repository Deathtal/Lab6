#pragma once
#include "SDL.h"
#include <iostream>

class Spritesheet {
private:
	SDL_Rect crop;
	SDL_Surface* spritesheet_surface;
	SDL_Texture* spritesheet_texture;
public:
	Spritesheet(char const* path, int row, int column, SDL_Renderer* renderer);
	~Spritesheet();

	void selectSprite(int x, int y);
	void drawSprite(SDL_Renderer* renderer, SDL_Rect* position, double angle, SDL_Point* center);
};