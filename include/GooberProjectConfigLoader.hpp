#pragma once

#include <string>

struct GooberProjectConfigLoader {
	
	int rayCount;
	int fov;
	int tileSize;
	int windowHeight;
	int windowWidth;

	static GooberProjectConfigLoader LoadProjectConfig(std::string filePath);	

};
