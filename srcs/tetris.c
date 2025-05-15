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
					else
						DrawRectangle(j * tetris.size, i * tetris.size, tetris.tet_size, tetris.tet_size, RED);
	
				}
			}
			DrawRectangle(12 * tetris.size, 0 * tetris.size, 10 * tetris.size, 22 * tetris.size, GRAY);
			DrawRectangle(12 * tetris.size, 1 * tetris.size, 7 * tetris.size, 8 * tetris.size, BLACK);
			DrawRectangle(12 * tetris.size, 10 * tetris.size, 7 * tetris.size, 11 * tetris.size, BLACK);
		EndDrawing();
	}
	CloseWindow();
	close_game(0);
	return (0);
}
