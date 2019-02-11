#pragma once

#include "box.h"

struct Player
{
	Box myBox;
	Box myBullets[500];
	int myBulletCount = 500;
	int myCurrentBullet;
	
	Player(int aX, int aY);
	bool Update(Box aCollision[], int aCollisionCount);
	void Draw(sf::RenderWindow& aWindow);
	void OnKeyTyped(sf::Keyboard::Key aKey);
	void OnKeyReleased(sf::Keyboard::Key aKey);
};