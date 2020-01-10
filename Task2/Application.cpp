#include "Application.h"

SDL_Renderer* createRenderer(SDL_Window** window, SDL_Renderer** renderer) { //initializes STL2 and is required to have the renderer be defined before player in the initializer list of Application
	SDL_Init(SDL_INIT_EVERYTHING);
	*window = SDL_CreateWindow("TankGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); //V-Sync is on
	return *renderer;
}

Application::Application() : player(275, 175, createRenderer(&window, &renderer)) {
	SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

Application::~Application() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Application::loop() {
	bool quit = false;
	SDL_Event event;
	while (!quit) {
		while (SDL_PollEvent(&event) > 0) {
			player.handle_events(event);
			if (event.type == SDL_QUIT) {
				quit = true;
				break;
			}
		}
		update();
		render();
		SDL_Delay(1000 / 60); //simple 60hz fps cap
	}
}

void Application::update() {
	player.update();
}

void Application::render() {
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderClear(renderer);
	player.draw();
	SDL_RenderPresent(renderer);
}