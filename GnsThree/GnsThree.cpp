#include "GnsThree.h"

int main() {
	int screenW{ 600 }, screenH{ 700 };
	InitWindow(screenW, screenH, "space shooter");
	SetTargetFPS(60);
	HideCursor();

	Player player{ screenW / 2 - 40,screenH / 2 + 200 };
	while(!WindowShouldClose()) {
		player.ps.x = GetMousePosition().x - 40;
		player.ps.y = GetMousePosition().y - 40;
		if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) player.Attack();
		player.UpdateProjectiles(screenH);

		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(player.texture, player.ps.x, player.ps.y, WHITE);
		for(const auto& p : player.projectiles)
			DrawRectangleRec(p, RED);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
