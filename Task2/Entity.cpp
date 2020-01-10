#include "Entity.h"

Entity::Entity(int x, int y) : x(x), y(y), speed_x(0), speed_y(0) {

}

Entity::~Entity() {

}

const int Entity::getX() const {
	return x;
}

const int Entity::getY() const {
	return y;
}

const int Entity::getSpeedX() const {
	return speed_x;
}

const int Entity::getSpeedY() const {
	return speed_y;
}

void Entity::setX(int x) {
	this->x = x;
}

void Entity::setY(int y) {
	this->y = y;
}

void Entity::setSpeedX(int speed) {
	this->speed_x = speed;
}

void Entity::setSpeedY(int speed) {
	this->speed_y = speed;
}

void Entity::modSpeedX(int speed_change) {
	speed_x += speed_change;
}

void Entity::modSpeedY(int speed_change) {
	speed_y += speed_change;
}

void Entity::modSpeeds(int speed_x, int speed_y) {
	this->speed_x = speed_x;
	this->speed_y = speed_y;
}

void Entity::move(double multi, SDL_Rect* obj_size_bounds) {
	if (!obj_size_bounds) {
		x += speed_x * multi;
		y += speed_y * multi;
	}
	else {
		if ((x <= 600 - obj_size_bounds->w && speed_x * multi > 0) || (x >= 0 && speed_x * multi < 0)) {
			x += speed_x * multi;
		}
		if ((y <= 400 - obj_size_bounds->h && speed_y * multi > 0) || (y >= 0 && speed_y * multi < 0)) {
			y += speed_y * multi;
		}
	}
}