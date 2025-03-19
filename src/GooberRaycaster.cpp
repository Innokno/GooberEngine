#include "GooberRaycaster.hpp"
#include "Player.hpp"
#include "SDL_render.h"
#include "constants.hpp"

#include <cmath>

GooberRaycaster::GooberRaycaster() {}

GooberRaycaster::GooberRaycaster(int rayCount, int fov, int tileSize, Player* player) {

	m_rayCount = rayCount;
	m_tileSize = tileSize;
	m_fov = fov;

	parentPlr = player;

}

void GooberRaycaster::Render(SDL_Renderer* renderer, int mapArray[][20]) {

	float constant = 320.0f;
	float distance = 0.0f;

	float lineHeight = 0.0f;
	float rotationAngle = parentPlr->GetPlayerRotation() -(m_fov * (PI / 180.0f)) / 2.0f;

	for (int i = 0; i < m_rayCount; i++) {

		distance = CastRay(mapArray, renderer, rotationAngle);

		distance *= cosf(parentPlr->GetPlayerRotation() - rotationAngle);

		GooberRaycaster::color *= (60 / distance);

		if (GooberRaycaster::color > 255) GooberRaycaster::color = 255;
		if (GooberRaycaster::color < 0) GooberRaycaster::color = 0;
		
		lineHeight = (32 / distance) * constant; 

		float start = (320.0f / 2) - (lineHeight / 2);
		float end = lineHeight;

		SDL_SetRenderDrawColor(renderer, color, color, color, 255);

		SDL_FRect rect = {float(i*4), start, 4, end };
		SDL_RenderFillRectF(renderer, &rect);

		rotationAngle += (m_fov * (PI / 180.0f)) / m_rayCount;	

	}
}

float GooberRaycaster::CastRay(int mapArray[][20], SDL_Renderer* renderer, float rotationAngle) {

	rotationAngle = NormaliseAngle(rotationAngle);

	float rayX = 0.0f;
	float rayY = 0.0f;

	float distance = 0.0f;
	float hDistance = 100000;
	float vDistance = 100000;

	float horizontalX = 0.0f;
	float horizontalY = 0.0f;

	float horizontalXOffset = 0.0f;
	float horizontalYOffset = 0.0f;

	bool skip = false;
	
	bool facing_right = rotationAngle > 1.5 * PI || rotationAngle < 0.5 * PI;
	bool facing_up = rotationAngle > PI && rotationAngle < 2 * PI;
	
	if (rotationAngle == 0 || rotationAngle == 2 * PI) {	
		horizontalY =  parentPlr->GetPlayerY();
		horizontalX = parentPlr->GetPlayerX();

		skip = true;
	}

	if (!facing_up) {
		
		horizontalYOffset = m_tileSize;
		horizontalY = floorf(parentPlr->GetPlayerY() / m_tileSize) * m_tileSize + m_tileSize;

	}

	else if (facing_up) {
		
		horizontalYOffset = -m_tileSize;
		horizontalY = floorf(parentPlr->GetPlayerY() / m_tileSize) * m_tileSize - 0.0001f;

	}

	horizontalXOffset = horizontalYOffset / tanf(rotationAngle);

	horizontalX = (horizontalY - parentPlr->GetPlayerY()) / tanf(rotationAngle) + parentPlr->GetPlayerX();

	while(horizontalX <= 640 && horizontalX >= 0 && horizontalY <= 320 && horizontalY >= 0) {

		if (skip) break; 

		int mapX = floorf(horizontalX / m_tileSize);
		int mapY = floorf(horizontalY / m_tileSize);

		if (mapX <= 20 && mapY <= 10  && mapX >= 0 && mapY >= 0 && mapArray[mapY][mapX] == 1) {
		
			hDistance = CalculateDistance(
					parentPlr->GetPlayerX(), 
					parentPlr->GetPlayerY(), 
					horizontalX, 
					horizontalY);

			break;

		}

		horizontalX += horizontalXOffset;
		horizontalY += horizontalYOffset;

	}

	skip = false;

	if (rotationAngle == 1.5f * PI || rotationAngle == 0.5f * PI) {	
		horizontalY =  parentPlr->GetPlayerY();
		horizontalX = parentPlr->GetPlayerX();

		skip = true;
	}
	
	float verticalY = 0.0f;
	float verticalX = 0.0f;

	float verticalXOffset = 0.0f;
	float verticalYOffset = 0.0f;

	if (!facing_right) {

		verticalXOffset = -m_tileSize;
		verticalX = floorf(parentPlr->GetPlayerX() / m_tileSize) * m_tileSize - 0.0001f;

	}

	else if (facing_right) {

		verticalXOffset = m_tileSize;
		verticalX = floorf(parentPlr->GetPlayerX() / m_tileSize) * m_tileSize + m_tileSize;

	}

	verticalYOffset = verticalXOffset * tanf(rotationAngle);

	verticalY = parentPlr->GetPlayerY() + (verticalX - parentPlr->GetPlayerX()) * tanf(rotationAngle);

	while(verticalX <= 640 && verticalX >= 0 && verticalY <= 320 && verticalY >= 0) {

		int mapX = floorf(verticalX / m_tileSize);
		int mapY = floorf(verticalY / m_tileSize);

		if (mapX <= 20 && mapY <= 10 && mapX >= 0 && mapY >= 0 && mapArray[mapY][mapX] == 1) {
			
			vDistance = CalculateDistance(
					parentPlr->GetPlayerX(), 
					parentPlr->GetPlayerY(), 
					verticalX, 
					verticalY);
			break;

		}

		verticalX += verticalXOffset;
		verticalY += verticalYOffset;

	}

	if (vDistance < hDistance) {
		
		rayX = verticalX;
		rayY = verticalY;

		color = 255.0f;

		return vDistance;

	}

	else if (hDistance < vDistance) {
		
		rayX = horizontalX;
		rayY = horizontalY;

		color = 160.0f;
		
		return hDistance;
	}

	return 1;
}

float GooberRaycaster::CalculateDistance(float x1, float y1, float x2, float y2) {
	
	float d = sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2)));

	return d;
}

float GooberRaycaster::NormaliseAngle(float rotationAngle) {

	rotationAngle = fmod(rotationAngle, 2*PI);

	if (rotationAngle <= 0) rotationAngle += 2*PI;

	return rotationAngle; 

}

void GooberRaycaster::Dispose() {

	if (isDisposed) {
		
		return;

	}

	isDisposed = true;
}
