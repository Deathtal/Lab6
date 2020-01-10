#include "Tank.h"
#include <algorithm>

Tank::Tank(int x, int y, SDL_Renderer* renderer) : Entity(x, y), spritesheet("TankSpritesheet.bmp", 1, 3, renderer), b_angle(0), t_angle(0), renderer(renderer), mouse_x(0), mouse_y(0), first_frame(1) {
	sprite_position = { x, y, 24, 24 }; //the size of the sprite used
	sprite_center = { 12, 12 }; //the center point of the sprite
}

Tank::~Tank() {
	for (Bullet* i : bullets) {
		delete i;
	}
}

void Tank::draw() {
	//draws the sprites of the tracks, turret and bullets
	spritesheet.drawSprite(renderer, &sprite_position, b_angle, &sprite_center);
	for (Bullet* i : bullets) { //draws the sprites of the bullets
		i->draw();
	}
	spritesheet.selectSprite(2, 0); //this changes from the tracks to the turret sprite
	spritesheet.drawSprite(renderer, &sprite_position, t_angle, &sprite_center);
}

void Tank::handle_events(const SDL_Event& event) {
	SDL_GetMouseState(&mouse_x, &mouse_y);
	t_angle = atan2(sprite_position.y + sprite_center.y - mouse_y, sprite_position.x + sprite_center.x - mouse_x) * 180 / M_PI - 90; //set angle of the turret to point towards the mouse cursor

	//keyboard and mouse input handling (still somewhat buggy)
	switch (event.type) {
	case SDL_MOUSEBUTTONDOWN:
		switch (event.button.button) {
		case SDL_BUTTON_LEFT:
			Bullet* bullet = new Bullet(getX() + sprite_center.x - 2, getY() + sprite_center.y - 2, t_angle, 8, renderer); //creates a new bullet and adds it to the bullets vector
			bullets.push_back(bullet);
			break;
		}
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_a:
			left = 1;
			break;
		case SDLK_d:
			right = 1;
			break;
		case SDLK_w:
			up = 1;
			break;
		case SDLK_s:
			down = 1;
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		switch (event.key.keysym.sym) {
		case SDLK_a:
			if (left) {
				left = 0;
			}
			break;
		case SDLK_d:
			if (right) {
				right = 0;
			}
			break;
		case SDLK_w:
			if (up) {
				up = 0;
			}
			break;
		case SDLK_s:
			if (down) {
				down = 0;
			}
			break;
		default:
			break;
		}
	default:
		break;
	}
	
	if (left) {
		if (right) {
			setSpeedX(0);
		}
		else if (up && !down) {
			setSpeedX(-2);
			setSpeedY(-2);
			b_angle = -45;
		}
		else if (down && !up) {
			setSpeedX(-2);
			setSpeedY(2);
			b_angle = -135;
		}
		else {
			setSpeedX(-4);
			setSpeedY(0);
			b_angle = -90;
		}
	}
	else if (right) {
		if (up && !down) {
			setSpeedX(2);
			setSpeedY(-2);
			b_angle = 45;
		}
		else if (down && !up) {
			setSpeedX(2);
			setSpeedY(2);
			b_angle = 135;
		}
		else {
			setSpeedX(4);
			setSpeedY(0);
			b_angle = 90;
		}
	}
	if (up && !(left + right == 1)) {
		if (down) {
			setSpeedY(0);
		}
		else {
			setSpeedX(0);
			setSpeedY(-4);
			b_angle = 0;
		}
	}
	else if (down && !(left + right == 1)) {
		setSpeedX(0);
		setSpeedY(4);
		b_angle = 180;
	}

	if ((!left && !right && !up && !down) || (left && right && !up && !down) || (!left && !right && up && down) || (left && right && up && down)) {
		setSpeedX(0);
		setSpeedY(0);
	}
}

void Tank::update() {
	//updates the x, y coordinates
	move(1, &sprite_position);
	sprite_position.x = getX();
	sprite_position.y = getY();

	for (Bullet* i : bullets) {
		if (i->getX() < -4 || i->getX() > 604 || i->getY() < -4 || i->getY() > 404) { //if the bullet is out of bounds remove from vector and delete it
			auto it = std::find(bullets.begin(), bullets.end(), i);
			bullets.erase(it);
			delete i;
		}
		else {
			i->update();
		}
	}

	//the spritesheet have 3 sprites, 2 of wich are the tracks. This code there so that it changes between the 2 track sprites when moving (sadly it's really hard to see)
	if (getSpeedX() && getSpeedY()) {
		if (first_frame) {
			first_frame = 0;
		}
		else {
			first_frame = 1;
		}
	}
	if (first_frame) {
		spritesheet.selectSprite(1, 0);
	}
	else {
		spritesheet.selectSprite(0, 0);
	}
}