#include "GooberGame.hpp"
#include "SDL_events.h"
#include "SDL_timer.h"

GooberGame::GooberGame(const char* name, std::string configFilePath) {
	
	GooberGame::InitGameWindow(name, configFilePath);
}

void GooberGame::Run() {

	Init();

	const float TIMESTEP = 1.0f / 60.0f;
	float accumulator = 0.0f;
	float deltaTime = 0.0f;
	float previousTime = SDL_GetTicks64();

	SDL_Event event;

	while (GooberGame::GetIsRunning()) {
		
		float currentTime = SDL_GetTicks64();
		deltaTime = (currentTime - previousTime) / 1000.0f;	
		previousTime = currentTime; 

		if (deltaTime < 0.001f) {
			
			deltaTime = 0.001f;

		}

		accumulator += deltaTime;

		while (SDL_PollEvent(&event)) {
			
			if (event.type == SDL_QUIT) {
				
				GooberGame::SetIsRunning(false);

			}
		
		}

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
