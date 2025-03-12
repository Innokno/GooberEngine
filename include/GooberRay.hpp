#pragma once
#include "GooberPoint.hpp"

// Defines what a ray(line)
// handles detecting of possible wall collisions
struct GooberRay {	
	GooberPoint m_startPoint;
	GooberPoint m_endPoint;

	GooberRay();
	GooberRay(GooberPoint startPoint, GooberPoint endPoint);		
};
