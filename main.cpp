#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <cstdint>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

int main() {
	
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window* window = SDL_CreateWindow("Pixel Drawing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING,
			WIDTH, HEIGHT);

	bool running = true;

//	uint32_t* pixels = new uint32_t[WIDTH*HEIGHT];

	SDL_Event event;

	while (running) {
		
		while (SDL_PollEvent(&event)) {

			std::cout << SDL_QUIT << std::endl;

			if (event.type == SDL_QUIT) {
				running = false;
			}

		}

		 SDL_SetRenderDrawColor(renderer, 255, 155, 0, 100);
		
//		 SDL_UpdateTexture(texture, nullptr, pixels, WIDTH * sizeof(uint32_t));

     SDL_RenderClear(renderer);
		 SDL_RenderCopy(renderer, texture, nullptr, nullptr);
     SDL_RenderPresent(renderer);
	}

//	 delete[] pixels;
	 SDL_DestroyTexture(texture);
   SDL_DestroyRenderer(renderer);
 	 SDL_DestroyWindow(window);
   SDL_Quit();
   return 0;
}
