#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <cstdint>

#include "goober/GameWindow.cpp"
#include "goober/GameWindow.hpp"

const int WIDTH = 800;
const int HEIGHT = 600;

int main() {

	GameWindow* gameWindow = new GameWindow(WIDTH, HEIGHT, "Hello World");

	SDL_Renderer* renderer = SDL_CreateRenderer(gameWindow->GetGameWindow(), -1, SDL_RENDERER_SOFTWARE);

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
	gameWindow->Dispose();
  SDL_Quit();
  return 0;
}
