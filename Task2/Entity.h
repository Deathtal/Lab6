#pragma once
#include "Spritesheet.h"

class Entity {
private:
	int x, y, speed_x, speed_y;
public:
	Entity(int x, int y);
	~Entity();

	const int getX() const;
	const int getY() const;
	const int getSpeedX() const;
	const int getSpeedY() const;
	void setX(int x);
	void setY(int y);
	void setSpeedX(int speed);
	void setSpeedY(int speed);
	void modSpeedX(int speed);
	void modSpeedY(int speed);
	void modSpeeds(int speed_x, int speed_y);
	void move(double multi = 1, SDL_Rect* obj_size_bounds = NULL);

	virtual void draw() = 0;
	virtual void update() = 0;
};