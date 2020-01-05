#pragma once
#include "Spritesheet.h"

class Entity {
private:
	float x, y;
	Spritesheet spritesheet;

public:
	Entity(Spritesheet spritesheet, float x, float y);
	~Entity();

	void drawSprite(SDL_Surface* window_surface, SDL_Rect* position);

	const float getX() const;
	const float getY() const;
	void setX(float x);
	void setY(float y);
};