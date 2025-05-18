#include "../include/tetris.h"

t_tetromino *allocate_tetromino(t_tetris *tetris)
{
	t_tetromino *tetromino;
	t_coord *coord;
	int	i = -1;

	coord = malloc(sizeof(t_coord) * 4);
	if (!coord)
		close_game(tetris, 3, false);
	tetromino = malloc(sizeof(t_tetromino));
	if (!tetromino)
		close_game(tetris, 2, false);
	while (++i < 5)
	{
		coord[i].x = 0;
		coord[i].y = 0;
	}
	tetromino->coord = coord;
	tetromino->type = 0;
	tetromino->colour = WALL_COLOUR;
	tetromino->orientation = LEFT;
	tetromino->detected = false;
	tetromino->is_rotating = false;
	tetromino->hard_drop = false;
	return (tetromino);
}

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
	tetris->current = NULL;
	tetris->next = NULL;
	tetris->held = NULL;
	tetris->hold = false;
	tetris->locked = false;
	tetris->prev = -1;
	tetris->score_int = 0;
	tetris->score_str = strdup("0");
	tetris->level_int = 1;
	tetris->level_str = strdup("1");
	tetris->level_prog = 0;
	tetris->btb = 0;
	change_speed(tetris);
	tetris->current = allocate_tetromino(tetris);
	tetris->next = allocate_tetromino(tetris);
	tetris->mrl_delay = 0.5f;
	tetris->time_since_last = 0.0f;
	tetris->delta_time = 1.0f / 60.0f;
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
	tetris->height = 960;
	tetris->width = 800;
	// tetris->height = 600;
	// tetris->width = 500;
	tetris->size = tetris->height / RATIO;
	tetris->tet_size = tetris->size - 1;

}
