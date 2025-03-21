#pragma once

#include <SDL2/SDL.h>

// Defines what a ray(line)
struct GooberRay {
	float rayAngle;

	SDL_Point startPoint;
	SDL_Point endPoint;

	GooberRay();
	GooberRay(float rayAngle, SDL_Point start, SDL_Point end);

};
