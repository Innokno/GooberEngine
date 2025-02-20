#pragma once

#include <SDL2/SDL.h>
#include <string>

struct ProjectConfig;

ProjectConfig LoadProjectConfig(std::string);

class GooberWindowManager {

	private:
		SDL_Window* gameWindow;
		SDL_Renderer* renderer;	

		bool running;
		bool isDisposed;

	public:
		int InitGameWindow(const char*, std::string); // return 0 if initialisation worked or -1 if not
		void Dispose();
};
