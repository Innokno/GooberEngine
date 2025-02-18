#include "GooberPoint.hpp"

GooberPoint::GooberPoint(float x, float y) {
	
	GooberPoint::m_xCoordinate = x;
	GooberPoint::m_yCoordinate = y;

}

float GooberPoint::GetXCoordinate() {
	return GooberPoint::m_xCoordinate;
}

float GooberPoint::GetYCoordinate() {
	return GooberPoint::m_yCoordinate;
}
