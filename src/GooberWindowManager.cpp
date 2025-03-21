#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>

#include "GooberWindowManager.hpp"
#include "GooberProjectConfigLoader.hpp"

GooberWindowManager::GooberWindowManager() {

	GooberWindowManager::isDisposed = false;	
	GooberWindowManager::isRunning = true;

}

int GooberWindowManager::GetFOV() {
	
	return m_configLoader.fov;

}

int GooberWindowManager::GetTileSize() {
	
	return m_configLoader.tileSize;
	
}

int GooberWindowManager::GetRayCount() {
	
	return m_configLoader.rayCount;

}

int GooberWindowManager::GetWindowHeight() {
		
	return m_configLoader.windowHeight;

}

int GooberWindowManager::GetWindowWidth() {
	
	return m_configLoader.windowWidth;

}

int GooberWindowManager::InitGameWindow(const char* name, std::string filePath) {
	m_configLoader = GooberProjectConfigLoader::LoadProjectConfig(filePath);

	SDL_Init(SDL_INIT_VIDEO);

	GooberWindowManager::gameWindow = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			m_configLoader.windowWidth, m_configLoader.windowHeight, SDL_WINDOW_SHOWN);

	if (GooberWindowManager::gameWindow == nullptr) {
	
		std::cout << SDL_GetError() << std::endl;
		return -1;

	}

	GooberWindowManager::renderer = SDL_CreateRenderer(GooberWindowManager::gameWindow, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (GooberWindowManager::renderer == nullptr) {
		
		std::cout << SDL_GetError() << std::endl;
		return -1;
			
	}		

	return 0;
}

bool GooberWindowManager::GetIsRunning() {
	
	return isRunning;

}

bool GooberWindowManager::GetIsDisposed() {
	
	return isDisposed;

}

void GooberWindowManager::SetIsRunning(bool value) {
	
	isRunning = value;

}

SDL_Window* GooberWindowManager::GetWindow() {
		
	return GooberWindowManager::gameWindow;

}

SDL_Renderer* GooberWindowManager::GetRenderer() {
	
	return GooberWindowManager::renderer;

}

void GooberWindowManager::Dispose() {
		
	if (GooberWindowManager::isDisposed) {	
		return;
	}
	
	GooberWindowManager::isDisposed = true;

	SDL_DestroyRenderer(GooberWindowManager::renderer);
	SDL_DestroyWindow(GooberWindowManager::gameWindow);	
}
