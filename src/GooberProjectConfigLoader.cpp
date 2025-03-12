#include <iostream>
#include <yaml-cpp/yaml.h>
#include "GooberProjectConfigLoader.hpp"

GooberProjectConfigLoader GooberProjectConfigLoader::LoadProjectConfig(std::string filePath) {
	
	YAML::Node configNode = YAML::LoadFile(filePath);	

	if (configNode.IsNull()) {
	
		std::cout << YAML::ErrorMsg::BAD_FILE << std::endl;

		return GooberProjectConfigLoader();

	}

	GooberProjectConfigLoader projectConfig = GooberProjectConfigLoader();	

	projectConfig.fov = configNode["fov"].as<int>();
	projectConfig.rayCount = configNode["rayCount"].as<int>();
	projectConfig.tileSize = configNode["tileSize"].as<int>();
	projectConfig.windowHeight = configNode["screen"]["height"].as<int>();
	projectConfig.windowWidth = configNode["screen"]["width"].as<int>();

	return projectConfig;
}
