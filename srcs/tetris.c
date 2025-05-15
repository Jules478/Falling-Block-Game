#include "../include/tetris.h"

void	close_game(int ex)
{
	exit(ex);
}


int	main()
{
	t_tetris tetris;
	int	i;
	int	j;

	srand(getpid());
	init_game(&tetris);
	SetTargetFPS(60);
	create_window(&tetris);
	InitWindow(tetris.width, tetris.height, "Tetris");
	draw_controls(&tetris);
	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(BLACK);
			i = -1;
			while (++i < 22)
			{
				j = -1;
				while (++j < 12)
				{
					if (tetris.map[i][j] == WALL)
						DrawRectangle(j * tetris.size, i * tetris.size, tetris.size, tetris.size, GRAY);
				}
			}
			DrawRectangle(12 * tetris.size, 0 * tetris.size, 10 * tetris.size, 22 * tetris.size, GRAY);
			DrawRectangle(12 * tetris.size, 1 * tetris.size, 7 * tetris.size, 9 * tetris.size, BLACK);
			DrawRectangle(12 * tetris.size, 11 * tetris.size, 7 * tetris.size, 10 * tetris.size, BLACK);
			DrawRectangle(12 * tetris.size, 5 * tetris.size, 7 * tetris.size, 1 * tetris.size, GRAY);
			DrawTexture(tetris.controls, 0 * tetris.size, 22 * tetris.size, WHITE);
			DrawText("Next", (12 * tetris.size) + 5, (1 * tetris.size) + 5, tetris.size - 1, WHITE);
			DrawText("Held", (12 * tetris.size) + 5, (6 * tetris.size) + 5, tetris.size - 1, WHITE);
			DrawText("High Scores:", (12 * tetris.size) + 5, (11 * tetris.size) + 5, tetris.size - 1, WHITE);
		EndDrawing();
	}
	UnloadTexture(tetris.controls);
	CloseWindow();
	close_game(0);
	return (0);
}
