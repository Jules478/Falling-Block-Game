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
	tetromino->times_moved = 0;
	tetromino->hard_drop = false;
	tetromino->on_ground = false;
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
	tetris->score = 0;
	tetris->level = 1;
	tetris->level_prog = 0;
	tetris->btb = 0;
	change_speed(tetris);
	tetris->current = allocate_tetromino(tetris);
	tetris->next = allocate_tetromino(tetris);
	tetris->mrl_delay = 30.0f;
	tetris->time_since_last = 0.0f;
	tetris->delta_time = 1.0f / 60.0f;
	tetris->queue = NULL;
	tetris->game_over = false;
	tetris->paused = false;
	fetch_high_scores(tetris);
}

void	create_window(t_tetris *tetris)
{
	float	h;
	float	w;

	InitWindow(100, 100, "Tetris");
	h = (float)GetMonitorHeight(0);
	w = (float)GetMonitorWidth(0);
	tetris->height = (int)(h * 0.89);
	tetris->width = (int)(w * 0.4);
	CloseWindow();
	tetris->size = tetris->height / RATIO;
	tetris->tet_size = tetris->size - 1;
	InitWindow(tetris->width, tetris->height, "Tetris");
	SetWindowPosition(((int)w - tetris->width) / 2, (((int)h - tetris->height) / 2) - 45);
}
