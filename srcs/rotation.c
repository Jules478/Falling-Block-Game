#include "../include/tetris.h"

void rotate_up(t_tetris *tetris)
{
	t_coord *temp;
	int	i = -1;

	temp = malloc(4 * sizeof(t_coord));
	if (!temp)
		close_game(tetris, 1, true);
	if (tetris->current->type == O_PIECE)
		return ;
	else if (tetris->current->type == I_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y + 1;
		temp[1].x = tetris->current->coord[1].x + 1;
		temp[1].y = tetris->current->coord[1].y;
		temp[2].x = tetris->current->coord[2].x + 2;
		temp[2].y = tetris->current->coord[2].y - 1;
		temp[3].x = tetris->current->coord[3].x - 1;
		temp[3].y = tetris->current->coord[3].y + 2;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		i = -1;
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = UP;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == S_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x + 1;
		temp[1].y = tetris->current->coord[1].y - 1;
		temp[2].x = tetris->current->coord[2].x;
		temp[2].y = tetris->current->coord[2].y + 2;
		temp[3].x = tetris->current->coord[3].x + 1;
		temp[3].y = tetris->current->coord[3].y + 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		i = -1;
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = UP;
		load_current_tetromino(tetris);
	}	
	else if (tetris->current->type == Z_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x;
		temp[1].y = tetris->current->coord[1].y - 1;
		temp[2].x = tetris->current->coord[2].x + 1;
		temp[2].y = tetris->current->coord[2].y + 2;
		temp[3].x = tetris->current->coord[3].x + 1;
		temp[3].y = tetris->current->coord[3].y + 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		i = -1;
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = UP;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == L_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x + 1;
		temp[1].y = tetris->current->coord[1].y - 1;
		temp[2].x = tetris->current->coord[2].x - 1;
		temp[2].y = tetris->current->coord[2].y + 1;
		temp[3].x = tetris->current->coord[3].x;
		temp[3].y = tetris->current->coord[3].y + 2;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		i = -1;
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = UP;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == J_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x + 1;
		temp[1].y = tetris->current->coord[1].y - 1;
		temp[2].x = tetris->current->coord[2].x - 1;
		temp[2].y = tetris->current->coord[2].y + 1;
		temp[3].x = tetris->current->coord[3].x + 2;
		temp[3].y = tetris->current->coord[3].y;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		i = -1;
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = UP;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == T_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x + 1;
		temp[1].y = tetris->current->coord[1].y - 1;
		temp[2].x = tetris->current->coord[2].x - 1;
		temp[2].y = tetris->current->coord[2].y + 1;
		temp[3].x = tetris->current->coord[3].x + 1;
		temp[3].y = tetris->current->coord[3].y + 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		i = -1;
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = UP;
		load_current_tetromino(tetris);
	}
}

void rotate_right(t_tetris *tetris)
{
	t_coord *temp;
	int	i = -1;

	temp = malloc(4 * sizeof(t_coord));
	if (!temp)
		close_game(tetris, 1, true);
	if (tetris->current->type == O_PIECE)
		return ;
	else if (tetris->current->type == I_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x - 1;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x;
		temp[1].y = tetris->current->coord[1].y + 1;
		temp[2].x = tetris->current->coord[2].x + 1;
		temp[2].y = tetris->current->coord[2].y + 2;
		temp[3].x = tetris->current->coord[3].x - 2;
		temp[3].y = tetris->current->coord[3].y - 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = RIGHT;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == S_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x + 1;
		temp[1].y = tetris->current->coord[1].y + 1;
		temp[2].x = tetris->current->coord[2].x - 2;
		temp[2].y = tetris->current->coord[2].y;
		temp[3].x = tetris->current->coord[3].x - 1;
		temp[3].y = tetris->current->coord[3].y + 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = RIGHT;
		load_current_tetromino(tetris);
	}	
	else if (tetris->current->type == Z_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x - 2;
		temp[1].y = tetris->current->coord[1].y + 1;
		temp[2].x = tetris->current->coord[2].x + 1;
		temp[2].y = tetris->current->coord[2].y;
		temp[3].x = tetris->current->coord[3].x - 1;
		temp[3].y = tetris->current->coord[3].y + 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = RIGHT;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == L_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x + 1;
		temp[1].y = tetris->current->coord[1].y + 1;
		temp[2].x = tetris->current->coord[2].x - 1;
		temp[2].y = tetris->current->coord[2].y - 1;
		temp[3].x = tetris->current->coord[3].x - 2;
		temp[3].y = tetris->current->coord[3].y;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = RIGHT;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == J_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x + 1;
		temp[1].y = tetris->current->coord[1].y + 1;
		temp[2].x = tetris->current->coord[2].x - 1;
		temp[2].y = tetris->current->coord[2].y - 1;
		temp[3].x = tetris->current->coord[3].x;
		temp[3].y = tetris->current->coord[3].y + 2;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = RIGHT;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == T_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x + 1;
		temp[1].y = tetris->current->coord[1].y + 1;
		temp[2].x = tetris->current->coord[2].x - 1;
		temp[2].y = tetris->current->coord[2].y - 1;
		temp[3].x = tetris->current->coord[3].x - 1;
		temp[3].y = tetris->current->coord[3].y + 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = RIGHT;
		load_current_tetromino(tetris);
	}
}

void rotate_down(t_tetris *tetris)
{
	t_coord *temp;
	int	i = -1;

	temp = malloc(4 * sizeof(t_coord));
	if (!temp)
		close_game(tetris, 1, true);
	if (tetris->current->type == O_PIECE)
		return ;
	else if (tetris->current->type == I_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y - 1;
		temp[1].x = tetris->current->coord[1].x - 1;
		temp[1].y = tetris->current->coord[1].y;
		temp[2].x = tetris->current->coord[2].x - 2;
		temp[2].y = tetris->current->coord[2].y + 1;
		temp[3].x = tetris->current->coord[3].x + 1;
		temp[3].y = tetris->current->coord[3].y - 2;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = DOWN;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == S_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x - 1;
		temp[1].y = tetris->current->coord[1].y + 1;
		temp[2].x = tetris->current->coord[2].x;
		temp[2].y = tetris->current->coord[2].y - 2;
		temp[3].x = tetris->current->coord[3].x - 1;
		temp[3].y = tetris->current->coord[3].y - 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = DOWN;
		load_current_tetromino(tetris);
	}	
	else if (tetris->current->type == Z_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x;
		temp[1].y = tetris->current->coord[1].y + 1;
		temp[2].x = tetris->current->coord[2].x - 1;
		temp[2].y = tetris->current->coord[2].y - 2;
		temp[3].x = tetris->current->coord[3].x - 1;
		temp[3].y = tetris->current->coord[3].y - 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = DOWN;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == L_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x - 1;
		temp[1].y = tetris->current->coord[1].y + 1;
		temp[2].x = tetris->current->coord[2].x + 1;
		temp[2].y = tetris->current->coord[2].y - 1;
		temp[3].x = tetris->current->coord[3].x;
		temp[3].y = tetris->current->coord[3].y - 2;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = DOWN;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == J_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x - 1;
		temp[1].y = tetris->current->coord[1].y + 1;
		temp[2].x = tetris->current->coord[2].x + 1;
		temp[2].y = tetris->current->coord[2].y - 1;
		temp[3].x = tetris->current->coord[3].x - 2;
		temp[3].y = tetris->current->coord[3].y;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = DOWN;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == T_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x - 1;
		temp[1].y = tetris->current->coord[1].y + 1;
		temp[2].x = tetris->current->coord[2].x + 1;
		temp[2].y = tetris->current->coord[2].y - 1;
		temp[3].x = tetris->current->coord[3].x - 1;
		temp[3].y = tetris->current->coord[3].y - 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = DOWN;
		load_current_tetromino(tetris);
	}
}

void rotate_left(t_tetris *tetris)
{
	t_coord *temp;
	int	i = -1;

	temp = malloc(4 * sizeof(t_coord));
	if (!temp)
		close_game(tetris, 1, true);
	if (tetris->current->type == O_PIECE)
		return ;
	else if (tetris->current->type == I_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x + 1;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x;
		temp[1].y = tetris->current->coord[1].y - 1;
		temp[2].x = tetris->current->coord[2].x - 1;
		temp[2].y = tetris->current->coord[2].y - 2;
		temp[3].x = tetris->current->coord[3].x + 2;
		temp[3].y = tetris->current->coord[3].y + 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = LEFT;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == S_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x - 1;
		temp[1].y = tetris->current->coord[1].y - 1;
		temp[2].x = tetris->current->coord[2].x + 2;
		temp[2].y = tetris->current->coord[2].y;
		temp[3].x = tetris->current->coord[3].x + 1;
		temp[3].y = tetris->current->coord[3].y - 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = LEFT;
		load_current_tetromino(tetris);
	}	
	else if (tetris->current->type == Z_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x + 2;
		temp[1].y = tetris->current->coord[1].y - 1;
		temp[2].x = tetris->current->coord[2].x - 1;
		temp[2].y = tetris->current->coord[2].y;
		temp[3].x = tetris->current->coord[3].x + 1;
		temp[3].y = tetris->current->coord[3].y - 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = LEFT;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == L_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x - 1;
		temp[1].y = tetris->current->coord[1].y - 1;
		temp[2].x = tetris->current->coord[2].x + 1;
		temp[2].y = tetris->current->coord[2].y + 1;
		temp[3].x = tetris->current->coord[3].x + 2;
		temp[3].y = tetris->current->coord[3].y;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = LEFT;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == J_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x - 1;
		temp[1].y = tetris->current->coord[1].y - 1;
		temp[2].x = tetris->current->coord[2].x + 1;
		temp[2].y = tetris->current->coord[2].y + 1;
		temp[3].x = tetris->current->coord[3].x;
		temp[3].y = tetris->current->coord[3].y - 2;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = LEFT;
		load_current_tetromino(tetris);
	}
	else if (tetris->current->type == T_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
		temp[1].x = tetris->current->coord[1].x - 1;
		temp[1].y = tetris->current->coord[1].y - 1;
		temp[2].x = tetris->current->coord[2].x + 1;
		temp[2].y = tetris->current->coord[2].y + 1;
		temp[3].x = tetris->current->coord[3].x + 1;
		temp[3].y = tetris->current->coord[3].y - 1;
		if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		tetris->current->coord = temp;
		tetris->current->orientation = LEFT;
		load_current_tetromino(tetris);
	}
}
/*
void	check_orientation(t_tetris *tetris)
{
	if (tetris->current->orientation == LEFT)
		rotate_up(tetris);
	else if (tetris->current->orientation == UP)
		rotate_right(tetris);
	else if (tetris->current->orientation == RIGHT)
		rotate_down(tetris);
	else if (tetris->current->orientation == DOWN)
		rotate_left(tetris);
	tetris->locked = false;
}*/

void check_orientation(t_tetris *tetris)
{
	float pivot_x = (float)tetris->current->coord[0].x;
	float pivot_y = (float)tetris->current->coord[0].y;
	float	x_rel;
	float y_rel;
	float	new_x;
	float new_y;
	int	i = 0;
	int	rot;
	t_coord *temp;

	tetris->locked = false;
	if (tetris->current->type == O_PIECE)
		return ;
	if (tetris->current->type == I_PIECE)
	{
 		switch (tetris->current->orientation)
	{
		case LEFT:
		{
			pivot_x = (float)(tetris->current->coord[0].x + tetris->current->coord[3].x) / 2;
			pivot_y = (float)(tetris->current->coord[0].y + tetris->current->coord[0].y + 1) / 2;
			rot = UP;
			break;
		}

		case UP:
		{
			pivot_x = (float)(tetris->current->coord[0].x + tetris->current->coord[0].x - 1) / 2;
			pivot_y = (float)(tetris->current->coord[0].y + tetris->current->coord[3].y) / 2;
			rot = RIGHT;
			break;
		}

		case RIGHT:
		{
			pivot_x = (float)(tetris->current->coord[0].x + tetris->current->coord[3].x) / 2;
			pivot_y = (float)(tetris->current->coord[0].y + tetris->current->coord[0].y - 1) / 2;
			rot = DOWN;
			break;
		}

		case DOWN:
		{
			pivot_x = (float)(tetris->current->coord[0].x + tetris->current->coord[0].x + 1) / 2;
			pivot_y = (float)(tetris->current->coord[0].y + tetris->current->coord[3].y) / 2;
			rot = LEFT;
			break;
		}
	}
		i = -1;
	}
	else
	{
		pivot_x = (float)tetris->current->coord[0].x;
		pivot_y = (float)tetris->current->coord[0].y;
	}
	temp = malloc(4 * sizeof(t_coord));
	if (!temp)
		close_game(tetris, 1, true);
	while (++i < 4)
	{
		x_rel = (float)tetris->current->coord[i].x - pivot_x;
		y_rel = (float)tetris->current->coord[i].y - pivot_y;
		
		new_x = -y_rel;
		new_y = x_rel;

		temp[i].x = (int)round(new_x + pivot_x);
		temp[i].y = (int)round(new_y + pivot_y);
	}
	if (tetris->current->type != I_PIECE)
	{
		temp[0].x = tetris->current->coord[0].x;
		temp[0].y = tetris->current->coord[0].y;
	}
	else
		tetris->current->orientation = rot;
	if (manage_collision(tetris, temp))
		{
			free(temp);
			return ;
		}
	i = -1;
	while (++i < 4)
		tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
	free(tetris->current->coord);
	tetris->current->coord = temp;
	load_current_tetromino(tetris);
}

