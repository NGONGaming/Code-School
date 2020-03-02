#pragma once

struct Box
{
	int x;
	int y;

	int height;
	int width;

	int vertical;
	int horizontal;

	bool valid;

	Box();
	Box(int aX, int aY, int aHeight, int aWidth);
	void Draw();
	bool Update(Box aCollision[], int aCollisionCount);
	void SetHorizontal(int aDistance);
	void SetVertical(int aDistance);
	void OnKeyTyped();
	void OnKeyReleased();
};