#include "GooberRaycaster.hpp"

GooberRaycaster::GooberRaycaster() {}

GooberRaycaster::GooberRaycaster(int rayCount, int fov,
		int tileSize) {
	
	m_tileSize = tileSize;
	m_fov = fov;

}

void GooberRaycaster::Dispose() {

	if (isDisposed) {
		
		return;

	}

	isDisposed = true;
	delete GooberRaycaster::m_rays;
}
