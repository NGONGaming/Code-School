#pragma once

#include <SFML/Graphics.hpp>

struct Box
{
	int x;
	int y;

	int height;
	int width;

	int vertical;
	int horizontal;

	bool valid;

	sf::RectangleShape rectangle;

	Box();
	Box(int aX, int aY, int aHeight, int aWidth);
	void Draw(sf::RenderWindow& aWindow);
	bool Update(Box aCollision[], int aCollisionCount);
	void SetHorizontal(int aDistance);
	void SetVertical(int aDistance);
	void OnKeyTyped(sf::Keyboard::Key aKey);
	void OnKeyReleased(sf::Keyboard::Key aKey);
};