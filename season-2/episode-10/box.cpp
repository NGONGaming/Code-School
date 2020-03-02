#include "box.h"

#include "raylib.h"

bool IsPointInsideBox(int x, int y, Box& aBox)
{
	bool isXInside = x >= aBox.x && x <= aBox.x + aBox.width;
	bool isYInside = y >= aBox.y && y <= aBox.y + aBox.height;

	return isXInside && isYInside;
}

bool IsBoxInsideBoxes(int aX, int aY, int aWidth, int aHeight, Box aCollision[], int aCollisionCount)
{
	for (int i = 0; i < aCollisionCount; i++)
	{
		Box& box = aCollision[i];
		if (!box.valid)
		{
			continue;
		}

		bool topLeftCollision = IsPointInsideBox(aX, aY, box);
		bool topRightCollision = IsPointInsideBox(aX + aWidth, aY, box);
		bool bottomLeftCollision = IsPointInsideBox(aX, aY + aHeight, box);
		bool bottomRightCollision = IsPointInsideBox(aX + aWidth, aY + aHeight, box);

		bool isCollision = topLeftCollision || topRightCollision || bottomLeftCollision || bottomRightCollision;
		if (isCollision)
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

	valid = true;
}

void Box::Draw()
{
	DrawRectangle(x, y, width, height, GRAY);
}

bool Box::Update(Box aCollision[], int aCollisionCount)
{
	bool isXCollision = IsBoxInsideBoxes(x + horizontal, y, width, height, aCollision, aCollisionCount);
	if (!isXCollision)
	{
		x = x + horizontal;
	}

	bool isYCollision = IsBoxInsideBoxes(x, y + vertical, width, height, aCollision, aCollisionCount);
	if (!isYCollision)
	{
		y = y + vertical;
	}

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

void Box::OnKeyTyped()
{
	if (IsKeyPressed(KEY_D))
	{
		horizontal = 1;
	}
	else if (IsKeyPressed(KEY_A))
	{
		horizontal = -1;
	}
	
	if (IsKeyPressed(KEY_W))
	{
		vertical = -1;
	}
	else if (IsKeyPressed(KEY_S))
	{
		vertical = 1;
	}
}

void Box::OnKeyReleased()
{
	if (IsKeyReleased(KEY_D) && horizontal > 0)
	{
		horizontal = 0;
	}
	else if (IsKeyReleased(KEY_A) && horizontal < 0)
	{
		horizontal = 0;
	}

	if (IsKeyReleased(KEY_W) && vertical < 0)
	{
		vertical = 0;
	}
	else if (IsKeyReleased(KEY_S) && vertical > 0)
	{
		vertical = 0;
	}
}