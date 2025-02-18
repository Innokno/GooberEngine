#pragma once
#include "GameWindowManager.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>
#include <cstdint>
#include <iostream>

GameWindowManager::GameWindowManager(const char* windowName, int width = 800, int height = 600) {
	GameWindowManager::m_isInitialised = true;
	GameWindowManager::m_isDisposed = false;

	GameWindowManager::m_windowWidth = width;
	GameWindowManager::m_windowHeight = height;

	GameWindowManager::m_mainPixelArray = new uint32_t[width * height];

	GameWindowManager::m_gameWindow = 
		SDL_CreateWindow(windowName, 
				SDL_WINDOWPOS_CENTERED, 
				SDL_WINDOWPOS_CENTERED,
				GameWindowManager::m_windowWidth,
				GameWindowManager::m_windowHeight,
				SDL_WINDOW_SHOWN);
	
	if (GameWindowManager::m_gameWindow == nullptr) {
		
		std::cout << SDL_GetError() << std::endl;
		return; 	
	}

	GameWindowManager::m_renderer = 
		SDL_CreateRenderer(
				GameWindowManager::m_gameWindow,
				-1, 
				SDL_RENDERER_SOFTWARE);

	if (GameWindowManager::m_renderer == nullptr) {
		
		std::cout << SDL_GetError() << std::endl;
		
		return;
	}

	GameWindowManager::m_mainTexture =
		SDL_CreateTexture(
				GameWindowManager::m_renderer,
				SDL_PIXELFORMAT_RGBA32, 
				SDL_TEXTUREACCESS_STREAMING,
				GameWindowManager::m_windowWidth,
				GameWindowManager::m_windowHeight);
	
	if (GameWindowManager::m_mainTexture == nullptr) {	
		std::cout << SDL_GetError() << std::endl;

		return;
	}

	SDL_SetRenderTarget(GameWindowManager::m_renderer, 
			GameWindowManager::m_mainTexture);

	std::cout << "0" << std::endl;
}

SDL_Renderer* GameWindowManager::GetRenderer() {
	
	return GameWindowManager::m_renderer;

}

SDL_Texture* GameWindowManager::GetMainTexture() {
	
	return GameWindowManager::m_mainTexture;

}

SDL_Window* GameWindowManager::GetGameWindow() {
	
	return GameWindowManager::m_gameWindow;

}

uint32_t* GameWindowManager::GetMainPixelArray() {
	return GameWindowManager::m_mainPixelArray;
}

void GameWindowManager::Dispose() {

	if (GameWindowManager::m_isDisposed) {	
		return;		
	}

	GameWindowManager::m_isDisposed = true;
	SDL_DestroyWindow(GameWindowManager::m_gameWindow);
	SDL_DestroyRenderer(GameWindowManager::m_renderer);
	SDL_DestroyTexture(GameWindowManager::m_mainTexture);
	delete[] GameWindowManager::m_mainPixelArray;
}

GameWindowManager::~GameWindowManager() {

	GameWindowManager::Dispose();

}
