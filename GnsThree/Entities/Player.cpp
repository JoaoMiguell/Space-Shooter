#include "Player.h"

Player::Player(int x, int y) {
	ps.x = x;
	ps.y = y;
	ps.width = 80;
	ps.height = 80;
}

void Player::Attack() {
	projectiles.push_back({ ps.x + 35,ps.y + 30,10,20 });
}

void Player::UpdateProjectiles(int screenH) {
	int i{ 0 };
	for(auto& p : projectiles) {
		if(p.y <= 0) {
			projectiles.erase(projectiles.begin() + i);
		}
		p.y -= 6;
		i++;
	}
}
