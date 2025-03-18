#include "GooberRay.hpp"

GooberRay::GooberRay(float rayAngle, SDL_Point start, SDL_Point end) {

	GooberRay::startPoint = start;
	GooberRay::endPoint = end;
	GooberRay::rayAngle = rayAngle;

}

GooberRay::GooberRay() {}
