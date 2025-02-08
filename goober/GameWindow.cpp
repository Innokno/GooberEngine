#pragma once
#include "GameWindow.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>
#include <cstdio>

GameWindow::GameWindow(int width, int height, const char* windowName, Uint32 flags = SDL_WINDOW_SHOWN) {
	GameWindow::m_isDisposed = false;

	SDL_Init(SDL_INIT_VIDEO);

	GameWindow::m_windowHeight = height;
	GameWindow::m_windowWidth = width;

	GameWindow::m_gameWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			width, height, flags);

	if (GameWindow::m_gameWindow == nullptr) {	
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", 
				SDL_GetError());

		SDL_DestroyWindow(GameWindow::m_gameWindow);
		SDL_Quit();
	}
}

void GameWindow::Dispose() {		
	if (GameWindow::m_isDisposed) {
		return;
	}

	if (GameWindow::m_gameWindow) {
		SDL_DestroyWindow(GameWindow::m_gameWindow);
		GameWindow::m_gameWindow = nullptr;
		GameWindow::m_isDisposed = true;
	}
}

GameWindow::~GameWindow() {
	GameWindow::Dispose();
}

SDL_Window*  GameWindow::GetGameWindow() {
	return GameWindow::m_gameWindow;
}


