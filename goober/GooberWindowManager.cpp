#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>

#include "GooberWindowManager.hpp"
#include <yaml-cpp/yaml.h>

struct ProjectConfig {
	
	int windowHeight;
	int windowWidth;
	int rayCount;
	int fov;
	int tileSize;

};

ProjectConfig LoadProjectConfig(std::string configFilePath) {
	ProjectConfig projectConfig = ProjectConfig();

	try {
		YAML::Node parsedConfigValues = YAML::LoadFile(configFilePath);	

		projectConfig.fov = parsedConfigValues["fov"].as<int>();
		projectConfig.rayCount = parsedConfigValues["rayCount"].as<int>();
		projectConfig.tileSize = parsedConfigValues["tileSize"].as<int>();
		projectConfig.windowHeight = parsedConfigValues["screen"]["height"].as<int>();
		projectConfig.windowWidth = parsedConfigValues["screen"]["width"].as<int>();

		return projectConfig;
	}
	catch (YAML::BadFile) {
		std::cout << YAML::ErrorMsg::BAD_FILE << std::endl;
	}

	return projectConfig;
}

int GooberWindowManager::InitGameWindow(const char* windowName, std::string configFilePath) {
	
	SDL_Init(SDL_INIT_VIDEO);

	ProjectConfig projectConfig = LoadProjectConfig(configFilePath);

	GooberWindowManager::gameWindow = 
		SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
				projectConfig.windowWidth, projectConfig.windowHeight, SDL_WINDOW_SHOWN);

	if (GooberWindowManager::gameWindow == nullptr) {
		
		std::cout << SDL_GetError() << std::endl;

		return -1;
	}

	GooberWindowManager::renderer = SDL_CreateRenderer(GooberWindowManager::gameWindow, -1, SDL_RENDERER_SOFTWARE);

	if (GooberWindowManager::renderer == nullptr) {
	
		std::cout << SDL_GetError() << std::endl;

		return -1;	
	}

	std::cout << "Finished initialising window" << std::endl;

	return 0;
}

void GooberWindowManager::Dispose() {
	
	if (GooberWindowManager::isDisposed) {
		return;
	}

	SDL_DestroyWindow(GooberWindowManager::gameWindow);
	SDL_DestroyRenderer(GooberWindowManager::renderer);
}
