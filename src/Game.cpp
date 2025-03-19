#include "GooberGame.hpp"
#include "GooberRaycaster.hpp"
#include "SDL_events.h"
#include "Player.hpp"
#include "SDL_render.h"
#include "constants.hpp"

#include <cmath>
#include <string>

class Game : public GooberGame {
	private:
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
			{1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
			{1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1},
			{1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1},
			{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1},
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

			rotationAngle += (turnDir * rotationSpeed * (PI / 180.0f)) * deltaTime;
		
			plr.SetPlayerRotation(rotationAngle);
			
			x += cos(rotationAngle) * (100 * moveDirection) * deltaTime;
			y += sin(rotationAngle) * (100 * moveDirection) * deltaTime;
		
			plr.SetPlayerPosition(x, y);

			raycaster.Render(GetRenderer(), map);

			SDL_RenderPresent(GetRenderer());
		}
		
	public:
		Game(const char* windowName, std::string configFilePath) : GooberGame(windowName, configFilePath) {}

};
