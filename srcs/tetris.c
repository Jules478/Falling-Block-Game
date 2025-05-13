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
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
	SetTargetFPS(60);
	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(RAYWHITE);
			i = -1;
			while (++i < 22)
			{
				j = -1;
				while (++j < 12)
				{
					DrawRectangle(j * SIZE, i * SIZE, SIZE - 1, SIZE - 1, RED);
				}
			}
		EndDrawing();
	}
	CloseWindow();
	close_game(0);
	return (0);
}
