#include "GooberGame.hpp"
#include "GooberRaycaster.hpp"
#include "SDL_events.h"
#include "Player.hpp"
#include "SDL_rect.h"
#include "SDL_render.h"

#include <iostream>
#include <cmath>
#include <string>

class Game : public GooberGame {
	private:
		const float PI = 3.1415926;
		
		GooberRaycaster raycaster;
		Player plr;

		float x;
		float y;

		float rotationAngle;
		float rotationSpeed;
		
		float moveDirection;
		float turnDir;

		int map[10][20] = 
		{
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
			{1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1},
			{1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1},
			{1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
			{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
			{1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1},
			{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		};

		SDL_Event event;

		void Init() override {

			rotationSpeed = 100;

			x = GetWindowWidth() / 2.0f;
			y = GetWindowHeight() / 2.0f;

			plr = { x, y, 10, 10, 10, 20};

			raycaster = { GetRayCount(), GetFOV(), GetTileSize(), &plr };

		}
		
		void Update(float deltaTime) override {

			SDL_PollEvent(&event);
				
			switch (event.type) {
				case SDL_QUIT:
					SetIsRunning(false);
					break;
				
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
						
						case SDLK_w:
							moveDirection = 1;
							break;
						
						case SDLK_s:
							moveDirection = -1;
							break;

						case SDLK_a:
							turnDir = -1;
							break;

						case SDLK_d:
							turnDir = 1;
							break;

					}

					break;

				case SDL_KEYUP:
					switch (event.key.keysym.sym) {
						
						case SDLK_w:
							if (moveDirection > 0) moveDirection = 0;
							break;

						case SDLK_s:
							if (moveDirection < 0) moveDirection = 0;
							break;

						case SDLK_a:
							if (turnDir < 0) turnDir = 0;
							break;

						case SDLK_d:
							if (turnDir > 0) turnDir = 0;
							break;

					}

				default:
					break;
			}

			SDL_SetRenderDrawColor(GetRenderer(), 0, 0, 0, 255);
			SDL_RenderClear(GetRenderer());

			for (int y = 0; y < 10; y++) {
				
				for (int x = 0; x < 20; x++) {
					int tileX = x * GetTileSize();
					int tileY = y * GetTileSize();
	
					SDL_Rect rect = {tileX, tileY, GetTileSize() - 1, GetTileSize() - 1};

					if (map[y][x] == 0) {

						SDL_SetRenderDrawColor(GetRenderer(), 255, 255, 255, 255);

					}
					
					else if (map[y][x] == 1) {

						SDL_SetRenderDrawColor(GetRenderer(), 40, 40, 40, 255);

					}

					SDL_RenderFillRect(GetRenderer(), &rect);
				}

			}

			rotationAngle += turnDir * rotationSpeed * (PI / 180) * deltaTime;
			
			rotationAngle = NormaliseRotationAngle(rotationAngle);

			plr.SetPlayerRotation(rotationAngle);

			x += cos(rotationAngle) * (100 * moveDirection) * deltaTime;
			y += sin(rotationAngle) * (100 * moveDirection) * deltaTime;
			
			plr.SetPlayerPosition(x, y);

			std::cout << rotationAngle << std::endl;

			SDL_SetRenderDrawColor(GetRenderer(), 255, 0, 0, 255);

			plr.RenderPlayerSprite(GetRenderer());
			
			SDL_RenderDrawLineF(GetRenderer(), plr.GetPlayerX(), plr.GetPlayerY(), 
					plr.GetPlayerX() + cos(rotationAngle) * 100, plr.GetPlayerY() + sin(rotationAngle) * 100);

			float ay;

			if (rotationAngle <= PI || rotationAngle >= (2.0f * PI)) {
				
				ay = floorf(plr.GetPlayerY() / GetTileSize()) * GetTileSize() + GetTileSize();	

			}

			else {
			
				ay = floorf(plr.GetPlayerY() / GetTileSize()) * GetTileSize() - 1;

			}

			float ax = (ay - plr.GetPlayerY()) / tanf(rotationAngle) + plr.GetPlayerX();

			float ay2;
			float ax2;

			ay2 = ay - GetTileSize();
			ax2 = ax - (GetTileSize() / tanf(rotationAngle));

			SDL_FRect rect = { ax - 5, ay - 5, 10, 10 };
			SDL_FRect rect2 = { ax2 - 5, ay2 - 5, 10, 10};

			SDL_RenderDrawRectF(GetRenderer(), &rect);
			SDL_RenderDrawRectF(GetRenderer(), &rect2);

			SDL_RenderPresent(GetRenderer());

		}

		float NormaliseRotationAngle(float rotationAngle) {
			
			rotationAngle = fmodf(rotationAngle, 2 * PI);
		
			if (rotationAngle < 0) rotationAngle = rotationAngle + (2 * PI);

			return rotationAngle;
			
		}
		
	public:
		Game(const char* windowName, std::string configFilePath) : GooberGame(windowName, configFilePath) {}

};
