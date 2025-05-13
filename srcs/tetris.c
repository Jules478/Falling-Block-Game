#include "../include/tetris.h"

void	close_game(int ex)
{
	exit(ex);
}


int	main()
{
	t_tetris tetris;

	srand(getpid());
	init_game(&tetris);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
	SetTargetFPS(60);
	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawRectangle(5, 5, 50, 50, I_COLOUR);
			DrawRectangle(55, 5, 50, 50, L_COLOUR);
			DrawRectangle(105, 5, 50, 50, J_COLOUR);
			DrawRectangle(155, 5, 50, 50, T_COLOUR);
			DrawRectangle(205, 5, 50, 50, S_COLOUR);
			DrawRectangle(255, 5, 50, 50, Z_COLOUR);
			DrawRectangle(305, 5, 50, 50, O_COLOUR);
		EndDrawing();
	}
	CloseWindow();
	close_game(0);
	return (0);
}
