#include "enemies.h"

#include "utils.h"

Enemies::Enemies(int aCount)
{
	myAliveCount = aCount;
	myEnemyCount = aCount;
	myEnemies = new Box[aCount];

	for(int i = 0; i < myEnemyCount; i++)
	{
		myEnemies[i] = Box(random(0, 800), random(0, 600), 32, 32);
	}
}

bool Enemies::Update(Box aCollision[], int aCollisionCount)
{
	for(int i = 0; i < myEnemyCount; i++)
	{
		if(myEnemies[i].valid)
		{
			bool collision = myEnemies[i].Update(aCollision, aCollisionCount);
			if(collision)
			{
				myEnemies[i].valid = false;
				myAliveCount--;
			}
		}
	}

	return false;
}

void Enemies::Draw(sf::RenderWindow& aWindow)
{
	for(int i = 0; i < myEnemyCount; i++)
	{
		if(myEnemies[i].valid)
		{
			myEnemies[i].Draw(aWindow);
		}
	}
}