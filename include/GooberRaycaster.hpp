#pragma once

#include <SDL2/SDL.h>
#include "GooberPoint.hpp"
#include "GooberRay.hpp"

// Handles casting all the rays
class GooberRaycaster {	
	private:
		bool isDisposed;

		int m_tileSize;
		int m_fov;

		GooberRay* m_rays;
	
	public:
		
		GooberRaycaster(int rayAmount, int fov, int tileSize);
		GooberRaycaster();

		// Draw line using x point of ray 
		int DrawLine(GooberPoint startPoint, GooberPoint endPoint); // Use SDL2 to draw a line using the information from {CastRay()}
		
		bool CastRay(GooberPoint startPoint, GooberPoint endPoint);

		void Dispose();
};
