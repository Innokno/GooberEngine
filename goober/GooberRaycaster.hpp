#pragma once

#include <SDL2/SDL.h>
#include <array>
#include "GooberRay.hpp"

// Handles casting all the rays
class GooberRaycaster {
	
	private:
		std::array<GooberRay, 80> rays;
		
		bool CastRay(GooberPoint, GooberPoint); //Check for rayhit
	
	public:
		// Draw line using x point of ray 
		int DrawLine(); // Use SDL2 to draw a line using the information from {CastRay()}	
};
