#include "GooberPoint.hpp"

// Defines what a ray(line) is
// handles detecting of possible wall collisions
struct Ray {	
	private:
		GooberPoint m_startPoint;
		GooberPoint m_endPoint;
	
	public:
		Ray(GooberPoint, GooberPoint);
};
