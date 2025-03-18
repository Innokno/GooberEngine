#pragma once

#include <SDL2/SDL.h>
#include "Player.hpp"
#include "SDL_render.h"

//Class that abstracts raycasting behaviour
class GooberRaycaster {	
	private:
		Player* parentPlr;

		bool isDisposed;

		int m_tileSize;
		int m_fov;
		int m_rayCount;

	public:
		void Render(SDL_Renderer* renderer);

		GooberRaycaster(int rayCount, int fov, int tileSize, Player* player);
		GooberRaycaster();

		void Dispose();
};
