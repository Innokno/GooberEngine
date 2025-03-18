#include "GooberRaycaster.hpp"
#include "Player.hpp"
#include "SDL_render.h"

GooberRaycaster::GooberRaycaster() {}

GooberRaycaster::GooberRaycaster(int rayCount, int fov,
		int tileSize, Player* player) {

	m_rayCount = rayCount;
	m_tileSize = tileSize;
	m_fov = fov;

	parentPlr = player;

}

void GooberRaycaster::Render(SDL_Renderer* renderer) {

	float rotationAngle = parentPlr->GetPlayerRotation() - ((90.0f * (3.1415926f / 180.0f) /2.0f));

	for (int i = 0; i < 160; i++) {
		
		SDL_RenderDrawLineF(renderer, parentPlr->GetPlayerX(), parentPlr->GetPlayerY(),
				parentPlr->GetPlayerX() + cos(rotationAngle) * 50, 
				parentPlr->GetPlayerY() + sin(rotationAngle) * 50);
	
		rotationAngle += (90.f * (3.1415926f / 180.0f) / 160.0f);	
		
	}
}

void GooberRaycaster::Dispose() {

	if (isDisposed) {
		
		return;

	}

	isDisposed = true;
}
