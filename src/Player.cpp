#include "Player.hpp"
#include "GooberPoint.hpp"

#include <SDL2/SDL_render.h>
#include <cmath>
#include <iostream>

Player::Player() {}

Player::Player(float x, float y, int height, int width, int mapRowAmount, int mapColumnAmount) {
	
	Player::playerSpriteHeight = height;
	Player::playerSpriteWidth = width;

	Player::mapColumnAmount = mapColumnAmount;
	Player::mapRowAmount = mapRowAmount;

	Player::playerPosition = {x, y};
}

void Player::RenderPlayerSprite(SDL_Renderer* renderer) {

	Player::playerSprite = { Player::playerPosition.m_xPos - (Player::playerSpriteWidth / 2.0f), 
		Player::playerPosition.m_yPos - (Player::playerSpriteHeight / 2.0f), 
	float(Player::playerSpriteWidth), 
	float(Player::playerSpriteHeight)};

	SDL_RenderFillRectF(renderer, &playerSprite);

}

void Player::PrintPlayerTile() {
		
	int x = floorf(Player::playerPosition.m_xPos / 32);
	int y = floorf(Player::playerPosition.m_yPos / 32);

	std::cout << "Tile Coordinates: (" << x << " " << y << ")" << std::endl;

}

float Player::GetPlayerRotation() {
	
	return Player::rotationAngle;

}

float Player::GetPlayerX() {
	
	return Player::playerPosition.m_xPos;
	
}

float Player::GetPlayerY() {
	
	return Player::playerPosition.m_yPos;

}

void Player::SetPlayerRotation(float rotationAngle) {
	
	Player::rotationAngle = rotationAngle;
	
}

void Player::SetPlayerPosition(float x, float y) {
		
	Player::playerPosition.m_xPos = x;
	Player::playerPosition.m_yPos = y;

} 
