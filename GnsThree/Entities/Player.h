#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>

class Player {
public:
	Texture2D texture{ LoadTexture("Assets/playerShip.png") };
	Rectangle ps{}; // p: position - s: size
	int velocity{ 2 };
	std::vector<Rectangle> projectiles{};

	Player(int x, int y);
	void Attack();
	void UpdateProjectiles(int screenH);
};