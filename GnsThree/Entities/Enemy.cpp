#include "Enemy.h"

Enemy::Enemy(int screenW, int screenH) {
	ps.x = rand() % (screenW - 60);
	ps.y = -60;
	ps.width = 51;
	ps.height = 33;
}

void Enemy::move() {
	ps.y += 2;
}

void Enemy::hit(int amount) {
	life -= amount;
}
