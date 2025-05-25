#include "../include/tetris.h"

bool	is_tetromino_coord(t_tetromino *tetromino, t_coord coord)
{
	int	i = -1;
	
	while (++i < 4)
	{
		if (tetromino->coord[i].x == coord.x && tetromino->coord[i].y == coord.y)
			return (true);
	}
	return (false);
}

bool	offset_collision(t_tetris *tetris, t_coord *coord)
{
	int	i = -1;
	while (++i < 4)
	{
		if (check_collision(tetris, coord[i].x, coord[i].y) && !is_tetromino_coord(tetris->current, coord[i]))
			return (false);
	}
	return (true);
}

int	manage_collision(t_tetris *tetris, t_coord *coord)
{
	int i;

	if (!offset_collision(tetris, coord))
	{
		i = -1;
		while (++i < 4)
			coord[i].y++;
		if (!offset_collision(tetris, coord))
		{
			i = -1;
			while (++i < 4)
				coord[i].y -= 2;
			if (!offset_collision(tetris, coord))
			{
				i = -1;
				while (++i < 4)
				{
					coord[i].y++;
					coord[i].x++;
				}
				if (!offset_collision(tetris, coord))
				{
					i = -1;
					while (++i < 4)
						coord[i].x -= 2;
					if (!offset_collision(tetris, coord))
						return (1);
				}
			}
		}
	}
	return (0);
}

bool	check_collision(t_tetris *tetris, int x, int y)
{
	if (x < 0 || x >= 12 || y < 0 || y >= 22)
		return (true);
	if (tetris->map[y][x] != EMPTY)
		return (true);
	return (false);
}

bool is_valid_position(t_tetris *tetris, int x, int y)
{
	if (x < 0 || x >= 12 || y < 0 || y >= 22)
		return (false);
	if (tetris->map[y][x] != EMPTY && !is_tetromino_coord(tetris->current, (t_coord){x, y}))
		return (false);
	return (true);
}

void	hard_drop(t_tetris *tetris)
{
	int	i;
	bool stop = false;
	
	while (1)
	{
		i = -1;
		if (stop == true)
		{
			load_current_tetromino(tetris);
			tetris->current->detected = true;
			break;
		}
		while (++i < 4)
		{
			if (!is_valid_position(tetris, tetris->current->coord[i].x, tetris->current->coord[i].y + 1))
			{
				stop = true;
				break;
			}
		}
		i = -1;
		while (++i < 4 && stop == false)
		{
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
			tetris->current->coord[i].y++;
		}
	}
}

void	lock_tetromino(t_tetris *tetris)
{
	free(tetris->current->coord);
	free(tetris->current);
	tetris->current = NULL;
	check_for_clears(tetris);
	tetris->current = tetris->next;
	tetris->next = allocate_tetromino(tetris);
	create_tetromino(tetris, tetris->next);
	draw_current_tetromino(tetris);
	check_game_over(tetris);
	if (tetris->game_over == true)
			return ;
	load_current_tetromino(tetris);
	tetris->hold = false;
	tetris->time_since_last = 0.0f;
	return;
}

void	check_lock(t_tetris *tetris)
{
	int i;

	if (tetris->current->on_ground)
	{
		i = -1;
		while (++i < 4)
		{
			if (!is_valid_position(tetris, tetris->current->coord[i].x, tetris->current->coord[i].y + 1))
			{
				if (tetris->time_since_last >= tetris->mrl_delay || tetris->current->hard_drop || tetris->current->times_moved > 14)
				{
					lock_tetromino(tetris);
					return ;
				}
			}
		}
		tetris->current->on_ground = false;
	}
}

void	check_pause(t_tetris *tetris)
{
	int	margin = tetris->size / 10;

	if (tetris->game_over == true)
		return ;
	if (IsKeyPressed(KEY_P))
		tetris->paused = !tetris->paused;
	if (tetris->paused == true)
	{
		DrawRectangle(2 * tetris->size, 7 * tetris->size, 8 * tetris->size, 3 * tetris->size, LIGHTGRAY);
		DrawRectangle((2 * tetris->size) + margin, (7 * tetris->size) + margin, (8 * tetris->size) - (margin * 2) - 1, (3 * tetris->size) - (margin * 2) - 1, BLACK);
		DrawText("Paused", (4 * tetris->size) + 5, (8 * tetris->size) + 5, tetris->size - 1, WHITE);
	}
}

int	intlen(int num)
{
	int len = 0;

	if (num == 0)
		return 1;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void change_speed(t_tetris *tetris)
{
	if (tetris->level > 15)
		return ;
	tetris->speed = 1.0f / time_steps[tetris->level];
}
