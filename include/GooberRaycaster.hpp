#pragma once

#include <SDL2/SDL.h>
#include "Player.hpp"

//Class that abstracts raycasting behaviour
class GooberRaycaster {	
	private:
		Player* parentPlr;

		bool isDisposed;

		int m_tileSize;
		int m_fov;
		int m_rayCount;

		float color;

		float CalculateDistance(float x1, float y1, float x2, float y2);
		float NormaliseAngle(float rotationAngle);
		
	public:
		void Render(SDL_Renderer* renderer, int mapArray[][20]);
		float CastRay(int mapArray[][20], SDL_Renderer* renderer, float rotationAngle);

		GooberRaycaster(int rayCount, int fov, int tileSize, Player* player);
		GooberRaycaster();

		void Dispose();
};
