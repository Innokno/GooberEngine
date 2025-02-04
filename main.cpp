#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <cstdint>
#include <SDL2/SDL.h>

const int WIDTH = 640;
const int HEIGHT = 480;

int main() {
	
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window* window = SDL_CreateWindow("Pixel Drawing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
			SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

	uint32_t* pixels = new uint32_t(WIDTH * HEIGHT);

	bool running = true;

	SDL_Event event;

	while (running) {
		
		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				running = false;
			}

		}

		 pixels[400 + 400 * WIDTH] = 0xFFFF0000;

     // Update texture and render
     SDL_UpdateTexture(texture, NULL, pixels, WIDTH * sizeof(uint32_t));
     SDL_RenderClear(renderer);
     SDL_RenderCopy(renderer, texture, NULL, NULL);
     SDL_RenderPresent(renderer);
	}

	 delete pixels;
   SDL_DestroyTexture(texture);
   SDL_DestroyRenderer(renderer);
 	 SDL_DestroyWindow(window);
   SDL_Quit();
   return 0;
}
