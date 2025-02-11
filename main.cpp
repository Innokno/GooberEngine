#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
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

	uint32_t* pixels = new uint32_t[WIDTH*HEIGHT];

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

		for (int i = 0; i < WIDTH; i++) {

			pixels[WIDTH * i + (WIDTH / 2)] = SDL_MapRGBA(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), 
					255, 255, 255, 255);

		}

		SDL_UpdateTexture(windowManager.GetMainTexture(), nullptr, pixels, WIDTH * sizeof(uint32_t));	
		SDL_RenderCopy(windowManager.GetRenderer(), windowManager.GetMainTexture(),
				nullptr, nullptr);

    SDL_RenderPresent(windowManager.GetRenderer());

		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - previousTime) / 1000.0f;
		previousTime = currentTime;
	}

	delete[] pixels;
	windowManager.Dispose();
  SDL_Quit();
  return 0;
}
