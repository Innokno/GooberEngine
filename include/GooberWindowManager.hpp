#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <string>

// Should only handle initialisation of the gamewindow
class GooberWindowManager {
	
	private:
		SDL_Window* gameWindow;
		SDL_Renderer* renderer;

		bool isDisposed;
		bool isRunning;

	public:
		GooberWindowManager();

		bool GetIsDisposed();
		bool GetIsRunning();

		SDL_Renderer* GetRenderer();

		void SetIsRunning(bool value);

		int InitGameWindow(const char* name, std::string filePath);		
		void Dispose();	
};

