#pragma once

#include "GooberPoint.hpp"
#include "SDL_rect.h"
#include "SDL_render.h"
#include <SDL2/SDL.h>

class Player {
	
	private:
		GooberPoint playerPosition;	
		SDL_FRect playerSprite;

		float rotationAngle;

		int mapRowAmount;
		int mapColumnAmount;

		int playerSpriteWidth;
		int playerSpriteHeight;

	public:

		void SetPlayerRotation(float rotationAngle);
		float GetPlayerRotation();

		void SetPlayerPosition(float x, float y);
		float GetPlayerX();
		float GetPlayerY();

		void PrintPlayerTile();

		void RenderPlayerSprite(SDL_Renderer* renderer);

		Player();
		Player(float x, float y, int height, int width, int mapRowAmount, int mapColumnAmount);

};
