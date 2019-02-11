#pragma once

#include "box.h"

struct Enemies
{
	Box* myEnemies;
	int myEnemyCount;
	int myAliveCount;
	
	Enemies(int aCount);
	bool Update(Box aCollision[], int aCollisionCount);
	void Draw(sf::RenderWindow& aWindow);
};