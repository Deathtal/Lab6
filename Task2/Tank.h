#pragma once
#include "Entity.h"
#include "Bullet.h"
#include <vector>

class Tank : public Entity {
private:
	SDL_Renderer* renderer;
	SDL_Rect sprite_position;
	SDL_Point sprite_center;
	Spritesheet spritesheet;
	double b_angle, t_angle;
	int mouse_x, mouse_y;
	bool first_frame;
	bool left = 0;
	bool right = 0;
	bool up = 0;
	bool down = 0;

	std::vector<Bullet*> bullets;

public:
	Tank(int x, int y, SDL_Renderer* renderer);
	~Tank();

	void draw();
	void handle_events(const SDL_Event &event);
	void update();
};