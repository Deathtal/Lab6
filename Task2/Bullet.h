#pragma once

#include "Entity.h"

class Bullet : public Entity {
private:
	SDL_Renderer* renderer;
	Spritesheet spritesheet;
	SDL_Rect sprite_position;
	SDL_Point sprite_center;
	double angle;

public:
	Bullet(int x, int y, double angle, int speed, SDL_Renderer* renderer);
	~Bullet() = default;

	void draw();
	void update();
};