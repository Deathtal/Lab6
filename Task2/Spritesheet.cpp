#include "Spritesheet.h"

Spritesheet::Spritesheet(char const* path, int row, int column, SDL_Renderer* renderer) {
	spritesheet_surface = SDL_LoadBMP(path);

	//crop crops the image so that you only view one sprite instead of the whole spritesheet
	crop.w = spritesheet_surface->w / column;
	crop.h = spritesheet_surface->h / row;

	spritesheet_texture = SDL_CreateTextureFromSurface(renderer, spritesheet_surface);
	if (!spritesheet_texture) {
		std::cout << SDL_GetError() << std::endl;
	}
}

Spritesheet::~Spritesheet() {
	SDL_FreeSurface(spritesheet_surface);
	SDL_DestroyTexture(spritesheet_texture);
}

void Spritesheet::selectSprite(int x, int y) {
	crop.x = x * crop.h;
	crop.y = y * crop.w;
}

void Spritesheet::drawSprite(SDL_Renderer* renderer, SDL_Rect* position, double angle, SDL_Point* center) {
	int result = SDL_RenderCopyEx(renderer, spritesheet_texture, &crop, position, angle, center, SDL_FLIP_NONE);
	if (result != 0) {
		std::cout << SDL_GetError() << std::endl;
	}
}