#pragma once

#include "Tank.h"

class Application {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	Tank player;
public:
	Application();
	~Application();

	void loop();
	void update();
	void render();
};