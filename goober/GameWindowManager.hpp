#pragma once
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <cstdint>

// structure that manages the initialisation of a window and renderer.
struct GameWindowManager {
	private:
		SDL_Window* m_gameWindow;
		SDL_Renderer* m_renderer;

		SDL_Texture* m_mainTexture;
		
		bool m_isInitialised;
		bool m_isDisposed;
	
		char* m_windowName;

		int m_windowWidth;
		int m_windowHeight;

uint32_t* m_mainPixelArray;

	public:
		GameWindowManager(const char*, int, int);	
	
		~GameWindowManager();
		
		void Dispose();

		SDL_Window* GetGameWindow();
		SDL_Renderer* GetRenderer();
		SDL_Texture* GetMainTexture();

		uint32_t* GetMainPixelArray();
};
