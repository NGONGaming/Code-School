#pragma once

#include "box.h"

struct Enemies
{
	Box* myEnemies;
	int myEnemyCount;
	int myAliveCount;

	Enemies(int aCount);
	~Enemies();

	bool Update(Box aCollision[], int aCollisionCount);
	void Draw();
};