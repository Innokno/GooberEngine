#include "GooberGame.hpp"
#include "GooberProjectConfigLoader.hpp"
#include "GooberRaycaster.hpp"
#include "SDL_render.h"

#include <string>
#include <iostream>

class Game : public GooberGame {
	private:
		GooberRaycaster rayCaster;
		GooberProjectConfigLoader configLoader;	

		void Init() override {
			configLoader = GooberProjectConfigLoader::LoadProjectConfig("../settings/config.yaml");

			rayCaster = GooberRaycaster(configLoader.rayCount, configLoader.fov, configLoader.tileSize);

			std::cout << configLoader.tileSize << std::endl;
		}
		
		void Update(float deltaTime) override {
			
			SDL_SetRenderDrawColor(GetRenderer(), 255, 255, 255, 255);
			SDL_RenderDrawLine(GetRenderer(), 10, 10, 10, 720);

			SDL_SetRenderDrawColor(GetRenderer(), 0, 0, 0, 255);

			SDL_RenderPresent(GetRenderer());
			SDL_RenderClear(GetRenderer());
		}

	public:
		Game(const char* windowName, std::string configFilePath) : GooberGame(windowName, configFilePath) {}

};
