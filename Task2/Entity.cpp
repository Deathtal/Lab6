#include "Entity.h"

Entity::Entity(Spritesheet spritesheet, float x, float y) : spritesheet(spritesheet), x(x), y(y) {

}

Entity::~Entity() {

}

const float Entity::getX() const {
	return x;
}

const float Entity::getY() const {
	return y;
}

void Entity::setX(float x) {
	this->x = x;
}

void Entity::setY(float y) {
	this->y = y;
}