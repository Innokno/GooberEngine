#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
//#include <iostream>

#include "goober/GooberWindowManager.hpp"
#include "goober/GooberWindowManager.cpp"

int main() {

	GooberWindowManager windowManager = GooberWindowManager();
	windowManager.InitGameWindow("Hello World", "../goober/settings/config.yaml");

	bool running = true;

	int currentTime = 0;
	int previousTime = 0;

	float distance = 0;
	float deltaTime = 0; 

	SDL_Event event;

	while (running) {
		
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;

			}

			else if (event.type == SDL_KEYDOWN) {

				switch (event.key.keysym.sym) {
					
					case SDLK_ESCAPE:
						running = false;
						break;
					case SDLK_w:
						distance += 100 * deltaTime;
						break;
					case SDLK_s:
						distance -= 100 * deltaTime;
						break;
				}
			}
		}

		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - previousTime) / 1000.0f;
		previousTime = currentTime;
	
		//std::cout << "DeltaTime: " << deltaTime << std::endl;	
	}

	windowManager.Dispose();
  SDL_Quit();
  return 0;
}
