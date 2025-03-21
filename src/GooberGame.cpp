#include "GooberGame.hpp"

#include <SDL2/SDL_timer.h>

GooberGame::GooberGame(const char* name, std::string configFilePath) {
	GooberGame::InitGameWindow(name, configFilePath);
}

void GooberGame::Run() {

	Init();

	const float TIMESTEP = 1.0f / 60.0f;
	float accumulator = 0.0f;
	float deltaTime = 0.0f;
	float previousTime = SDL_GetTicks64();

	while (GooberGame::GetIsRunning()) {
		
		float currentTime = SDL_GetTicks();
		deltaTime = (currentTime - previousTime) / 1000.0f;	
		previousTime = currentTime; 

		if (deltaTime < 0.001f) {
			
			deltaTime = 0.001f;

		}

		accumulator += deltaTime;

		while (accumulator >= TIMESTEP) {
			
			Update(TIMESTEP);
			accumulator -= TIMESTEP;
				
		}

	}

	if (!GooberGame::GetIsDisposed()) {
	
		GooberGame::Dispose();
		
	}

	SDL_Quit();
}

void GooberGame::Update(float deltaTime) {}
void GooberGame::Init() {}
