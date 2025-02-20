#include "GooberPoint.hpp"

// Defines what a ray(line) is
// handles detecting of possible wall collisions
struct GooberRay {	
	GooberPoint m_startPoint;
	GooberPoint m_endPoint;
	
	GooberRay(GooberPoint, GooberPoint);		
};
