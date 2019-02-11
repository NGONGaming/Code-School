#include "box.h"

#include "utils.h"

bool IsPointInsideBox(int x, int y, Box& aBox)
{
	bool isXInside = x >= aBox.x && x <= aBox.x + aBox.width;
	bool isYInside = y >= aBox.y && y <= aBox.y + aBox.height;
	
	return isXInside && isYInside;
}

bool IsBoxInsideBoxes(int aX, int aY, int aWidth, int aHeight, Box aCollision[], int aCollisionCount, int aRegionX, int aRegionY)
{
	for(int i = 0; i < aCollisionCount; i++)
	{
		Box& box = aCollision[i];
		if(!box.valid
			|| (box.regionX != aRegionX && box.regionY != aRegionY))
		{
			continue;
		}

		if (IsPointInsideBox(aX, aY, box))
		{
			return true;
		}

		if (IsPointInsideBox(aX + aWidth, aY, box))
		{
			return true;
		}

		if (IsPointInsideBox(aX, aY + aHeight, box))
		{
			return true;
		}

		if (IsPointInsideBox(aX + aWidth, aY + aHeight, box))
		{
			return true;
		}
	}
	
	return false;
}

Box::Box()
{
	x = 0;
	y = 0;

	height = 0;
	width = 0;

	vertical = 0;
	horizontal = 0;

	regionX = 0;
	regionY = 0;

	valid = false;
}

Box::Box(int aX, int aY, int aHeight, int aWidth)
{
	x = aX;
	y = aY;
		
	height = aHeight;
	width = aWidth;
		
	vertical = 0;
	horizontal = 0;

	regionX = ((x + 25) / 50) * 50;
	regionY = ((y + 25) / 50) * 50;

	valid = true;
	rectangle = sf::RectangleShape(sf::Vector2f(width, height));
}
	
void Box::Draw(sf::RenderWindow& aWindow)
{
	aWindow.draw(rectangle);
}

bool Box::Update(Box aCollision[], int aCollisionCount)
{
	bool isXCollision = IsBoxInsideBoxes(x + horizontal, y, width, height, aCollision, aCollisionCount, regionX, regionY);
	if(!isXCollision)
	{
		x = x + horizontal;
	}

	bool isYCollision = IsBoxInsideBoxes(x, y + vertical, width, height, aCollision, aCollisionCount, regionX, regionY);
	if(!isYCollision)
	{
		y = y + vertical;
	}
	
	regionX = ((x + 50) / 100) * 100;
	regionY = ((y + 50) / 100) * 100;

	rectangle.setPosition(x, y);
		
	return isXCollision || isYCollision;
}
	
void Box::SetHorizontal(int aDistance)
{
	horizontal = aDistance;
}
	
void Box::SetVertical(int aDistance)
{
	vertical = aDistance;
}

void Box::OnKeyTyped(sf::Keyboard::Key aKey)
{
	if(aKey == sf::Keyboard::D)
	{
		horizontal = 1;
	}
	else if(aKey == sf::Keyboard::A)
	{
		horizontal = -1;
	}
	else if(aKey == sf::Keyboard::W)
	{
		vertical = -1;
	}
	else if(aKey == sf::Keyboard::S)
	{
		vertical = 1;
	}
}
	
void Box::OnKeyReleased(sf::Keyboard::Key aKey)
{
	if(aKey == sf::Keyboard::D && horizontal > 0)
	{
		horizontal = 0;
	}
	else if(aKey == sf::Keyboard::A && horizontal < 0)
	{
		horizontal = 0;
	}
	else if(aKey == sf::Keyboard::W && vertical < 0)
	{
		vertical = 0;
	}
	else if(aKey == sf::Keyboard::S && vertical > 0)
	{
		vertical = 0;
	}
}
