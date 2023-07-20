#pragma once
#include <stdlib.h>
#include "raylib.h"

class Enemy {
public:
	Texture2D texture{ LoadTexture("Assets/enemyShip.png") };
	Rectangle ps{};
	int life{ 10 };

	Enemy(int screenW, int screenH);
	void move();
	void hit(int amount);
};