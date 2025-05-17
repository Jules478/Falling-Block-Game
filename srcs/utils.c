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

int	manage_collision(t_tetris *tetris, t_coord *coord)
{
	int	i = -1;
	while (++i < 4)
	{
		if (floor_collision(tetris, coord[i].x, coord[i].y) && !is_tetromino_coord(tetris->current, coord[i]))
		{
			i = -1;
			while (++i < 4)
				coord[i].y++;
			if (floor_collision(tetris, coord[i].x, coord[i].y) && !is_tetromino_coord(tetris->current, coord[i]))
			{
				i = -1;
				while (++i < 4)
					coord[i].y -=2;
				if (floor_collision(tetris, coord[i].x, coord[i].y) && !is_tetromino_coord(tetris->current, coord[i]))
					return (1);
				break;
			}
			break;
		}
	}
	i = -1;
	while (++i < 4)
	{
		if (wall_collision(tetris, coord[i].x, coord[i].y) && !is_tetromino_coord(tetris->current, coord[i]))
		{
			i = -1;
			while (++i < 4)
				coord[i].x--;
			i = -1;
			while (++i < 4)
			{
				if (wall_collision(tetris, coord[i].x, coord[i].y) && !is_tetromino_coord(tetris->current, coord[i]))
				{
					i = -1;
					while (++i < 4)
						coord[i].x += 2;
					i = -1;
					while (++i < 4)
					{
						if (wall_collision(tetris, coord[i].x, coord[i].y) && !is_tetromino_coord(tetris->current, coord[i]))
							return (1);
					}
					break;
				}
			}
			break;
		}
	}
	return (0);
}

bool	floor_collision(t_tetris *tetris, int x, int y)
{
	if (x < 0 || x >= 12 || y < 0 || y >= 22)
		return (true);
	if (tetris->map[y][x] != EMPTY)
		return (true);
	return (false);
}

bool	wall_collision(t_tetris *tetris, int x, int y)
{
	if (x < 0 || x >= 12 || y < 0 || y >= 22)
		return (true);
	if (tetris->map[y][x] != EMPTY)
		return (true);
	return (false);
}

bool is_valid_position_go(t_tetris *tetris, int x, int y)
{
	if (x < 0 || x >= 12 || y < 0 || y >= 22)
		return (false);
	if (tetris->map[y][x] != EMPTY)
		return (false);
	return (true);
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

char *tet_itoa(t_tetris *tetris, int x)
{
	int	len;
	char *str;

	len = snprintf(NULL, 0, "%d", x);
	str = malloc(len + 1);
	if (!str)
		close_game(tetris, 1, true);
	snprintf(str, len + 1, "%d", x);
	return (str);
}
