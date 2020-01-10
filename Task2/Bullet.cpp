#include "Bullet.h"

Bullet::Bullet(int x, int y, double angle, int speed, SDL_Renderer* renderer) : Entity(x, y), spritesheet("bullet.bmp", 1, 1, renderer), renderer(renderer), angle(angle) {
	setSpeedX(sin(M_PI * angle / 180.0) * speed);
	setSpeedY(-cos(M_PI * angle / 180.0) * speed);
	sprite_position = { x, y, 4, 4 }; //the size of the sprite used
	sprite_center = { 2, 2 }; //the center point of the sprite
}

void Bullet::draw() {
	spritesheet.drawSprite(renderer, &sprite_position, angle, &sprite_center);
}

void Bullet::update() {
	move();
	sprite_position.x = getX();
	sprite_position.y = getY();
}