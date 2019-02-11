#include "player.h"

#include "utils.h"

Player::Player(int aX, int aY)
	: myBox(aX, aY, 32, 32)
{
	myBulletCount = 500;
	myCurrentBullet = 0;
}

bool Player::Update(Box aCollision[], int aCollisionCount)
{
	for(int i = 0; i < myBulletCount; i++)
	{
		Box& bullet = myBullets[i];
		if(bullet.valid)
		{
			bullet.Update(nullptr, 0);
		}
	}

	return myBox.Update(aCollision, aCollisionCount);
}

void Player::Draw(sf::RenderWindow& aWindow)
{
	myBox.Draw(aWindow);
	
	for(int i = 0; i < myBulletCount; i++)
	{
		Box& bullet = myBullets[i];
		if(bullet.valid)
		{
			bullet.Draw(aWindow);
		}
	}
}

void Player::OnKeyTyped(sf::Keyboard::Key aKey)
{
	myBox.OnKeyTyped(aKey);
	
	if(aKey == sf::Keyboard::Space)
	{
		myBullets[myCurrentBullet] = Box(myBox.x, myBox.y, 8, 16);
		myBullets[myCurrentBullet].SetHorizontal(random(-5,5));
		myBullets[myCurrentBullet].SetVertical(random(-5,5));

		myCurrentBullet = myCurrentBullet + 1;
		if(myCurrentBullet == myBulletCount)
		{
			myCurrentBullet = 0;
		}
	}
}

void Player::OnKeyReleased(sf::Keyboard::Key aKey)
{
	myBox.OnKeyReleased(aKey);
}
