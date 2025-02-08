#pragma once
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>

struct GameWindow {

	private:
		SDL_Window* m_gameWindow;

		bool m_isDisposed;

		int m_windowWidth;
		int m_windowHeight;

	public:
		GameWindow(int, int, const char*, Uint32);
		~GameWindow();

		void Dispose();

		SDL_Window* GetGameWindow();	
};
