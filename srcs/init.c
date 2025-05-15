#include "../include/tetris.h"

void	init_game(t_tetris *tetris)
{
	int	i = -1;
	int	j;

	while (++i < 22)
	{
		j = -1;
		while (++j < 12)
		{
			if (j == 0 || i == 0 || j == 11 || i == 21)
				tetris->map[i][j] = WALL;
			else
				tetris->map[i][j] = EMPTY;
		}
	}
	i = -1;
	while (++i < 22)
	{
		j = -1;
		while (++j < 12)
		{
			printf("%d", tetris->map[i][j]);
		}
		printf("\n");
	}
}

void	create_window(t_tetris *tetris)
{
	// float	h;
	// float	w;

	// if (GetMonitorCount() < 1)
	// {
	// 	tetris->width = 500;
	// 	tetris->height = 600;
	// 	return ;
	// }
	// h = (float)GetMonitorHeight(1);
	// w = (float)GetMonitorWidth(1);
	// tetris->height = (int)(h / 1.8);
	// tetris->width = (int)(w / 3.84);
	// printf("width: %d\n", tetris->width);
	// printf("height: %d\n", tetris->height);
	tetris->height = 1200;
	tetris->width = 1000;
	tetris->size = tetris->height / RATIO;
	tetris->tet_size = tetris->size - 1;
}
