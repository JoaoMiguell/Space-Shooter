#include "GnsThree.h"

int main() {
	int screenW{ 600 }, screenH{ 700 };
	InitWindow(screenW, screenH, "space shooter");
	SetTargetFPS(60);
	HideCursor();

	Player player{ screenW / 2 - 40,screenH / 2 + 200 };
	std::vector<Enemy> enemys{};
	int timeLapsedToGenEnemy{ 0 };
	int enemyGenTime{ 30 };

	while(!WindowShouldClose()) {
		player.ps.x = GetMousePosition().x - 40;
		player.ps.y = GetMousePosition().y - 40;
		if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) player.Attack();
		player.UpdateProjectiles(screenH);

		if(timeLapsedToGenEnemy == enemyGenTime) {
			enemys.push_back({ screenW,screenH });
			timeLapsedToGenEnemy = 0;
		}
		else timeLapsedToGenEnemy++;

		for(auto e{ enemys.begin() }; e != enemys.end(); ++e) {
			if(e->ps.y > screenH) {
				UnloadTexture(e->texture);
				enemys.erase(e);
				e = enemys.begin();
			}
			else e->move();

			for(auto p{ player.projectiles.begin() }; p != player.projectiles.end(); ++p) {
				if(CheckCollisionRecs(e->ps, *p)) {
					e->hit(player.damage);
					if(e->life <= 0) {
						UnloadTexture(e->texture);
						enemys.erase(e);
						e = enemys.begin();

					}
 					player.projectiles.erase(p);

					if(player.projectiles.size() == 0) break;
					else p = player.projectiles.begin();
				}
			}
		}

		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(player.texture, player.ps.x, player.ps.y, WHITE);

		for(const auto& p : player.projectiles)
			DrawRectangleRec(p, RED);

		for(const auto& e : enemys)
			DrawTexture(e.texture, e.ps.x, e.ps.y, WHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
