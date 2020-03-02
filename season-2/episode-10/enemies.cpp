#include "enemies.h"

#include "ngon_utils.h"

Enemies::Enemies(int aCount)
{
	myAliveCount = aCount;
	myEnemyCount = aCount;
	myEnemies = new Box[aCount];

	for (int i = 0; i < myEnemyCount; i++)
	{
		myEnemies[i] = Box(random(0, 800), random(0, 600), 32, 32);
	}
}

Enemies::~Enemies()
{
	delete [] myEnemies;
}

bool Enemies::Update(Box aCollision[], int aCollisionCount)
{
	for (int i = 0; i < myEnemyCount; i++)
	{
		if (myEnemies[i].valid)
		{
			bool collision = myEnemies[i].Update(aCollision, aCollisionCount);
			if (collision)
			{
				myEnemies[i].valid = false;
				myAliveCount--;
			}
		}
	}

	return false;
}

void Enemies::Draw()
{
	for (int i = 0; i < myEnemyCount; i++)
	{
		if (myEnemies[i].valid)
		{
			myEnemies[i].Draw();
		}
	}
}