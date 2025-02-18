#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <cstdint>

#include "goober/GameWindowManager.cpp"

const int WIDTH = 1000;
const int HEIGHT = 800;

int main() {

	GameWindowManager windowManager = GameWindowManager("Hello World", WIDTH, HEIGHT);

	bool running = true;

	int currentTime = 0;
	int previousTime = 0;

	float distance = 0;
	float deltaTime = 0; 

	uint32_t* pixels = windowManager.GetMainPixelArray();

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

		SDL_SetRenderDrawColor(windowManager.GetRenderer(), 0, 0, 0, 255);
		SDL_RenderClear(windowManager.GetRenderer());

		SDL_SetRenderDrawColor(windowManager.GetRenderer(), 255, 255, 255, 255);
		SDL_RenderDrawLine(windowManager.GetRenderer(), 0, 0, 0, 800);

    SDL_RenderPresent(windowManager.GetRenderer());

		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - previousTime) / 1000.0f;
		previousTime = currentTime;
	
		std::cout << "DeltaTime: " << deltaTime << std::endl;	
	}

	windowManager.Dispose();
  SDL_Quit();
  return 0;
}
