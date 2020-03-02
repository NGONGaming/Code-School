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
	void Draw();
	void OnKeyTyped();
	void OnKeyReleased();
};