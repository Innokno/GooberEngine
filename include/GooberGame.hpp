#pragma once

#include "GooberWindowManager.hpp"
#include <string>

class GooberGame : public GooberWindowManager {
	public:
		GooberGame(const char* name, std::string configFilePath);
		void Run();

	protected:
		virtual void Init();
		virtual void Update(float deltaTime);
};
