#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <cstdint>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

int main() {
	
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window* window = SDL_CreateWindow("Pixel Drawing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	SDL_Texture* mainGameTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, 
			WIDTH, HEIGHT); 

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

		std::cout << distance << std::endl;

		SDL_UpdateTexture(mainGameTexture, nullptr, pixels, WIDTH * sizeof(uint32_t));	
		SDL_RenderCopy(renderer, mainGameTexture, nullptr, nullptr);

    SDL_RenderPresent(renderer);

		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - previousTime) / 1000.0f;
		previousTime = currentTime;
	}

	delete[] pixels;
	SDL_DestroyTexture(mainGameTexture);
  SDL_DestroyRenderer(renderer);
 	SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
