#include "../include/tetris.h"

void	check_game_over(t_tetris *tetris)
{
	int	i = -1;

	while (++i < tetris->current->collision)
	{
		if (tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] != EMPTY)
			close_game(tetris, 0, true);
	}
}

void	advance_one_stage(t_tetris *tetris)
{
	int	i = -1;
	int	j = -1;
	bool	collision = false;

	if (tetris->current->detected == true)
	{
		free(tetris->current->coord);
		free(tetris->current);
		tetris->current = tetris->next;
		tetris->next = allocate_tetromino(tetris);
		create_tetromino(tetris->next);
		draw_current_tetromino(tetris);
		check_game_over(tetris);
		load_current_tetromino(tetris);
		return ;
	}
	if (tetris->current->orientation == LEFT)
	{
		while (++j < tetris->current->collision)
		{
			if (tetris->map[tetris->current->coord[j].y + 1][tetris->current->coord[j].x] != EMPTY)
			{
				collision = true;
				tetris->current->detected = true;
				break ;
			}
		}
		while (++i < 4 && collision == false)
		{
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
			tetris->current->coord[i].y++;				
		}
	}
	load_current_tetromino(tetris);
}

void	detect_input(t_tetris *tetris)
{
	int	i = -1;
	if (IsKeyPressed(KEY_LEFT))
	{
		while (++i < 4)
		{
			if (!is_valid_position(tetris, tetris->current->coord[i].x - 1, tetris->current->coord[i].y))
				return ;
		}
		i = -1;
		while (++i < 4)
		{
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
			tetris->current->coord[i].x--;
			load_current_tetromino(tetris);
		}
	}
	else if (IsKeyPressed(KEY_RIGHT))
	{
		while (++i < 4)
		{
			if (!is_valid_position(tetris, tetris->current->coord[i].x + 1, tetris->current->coord[i].y))
				return ;
		}
		i = -1;
		while (++i < 4)
		{
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
			tetris->current->coord[i].x++;
			load_current_tetromino(tetris);
		}
	}
	else if (IsKeyPressedRepeat(KEY_LEFT))
	{
		while (++i < 4)
		{
			if (!is_valid_position(tetris, tetris->current->coord[i].x - 1, tetris->current->coord[i].y))
				return ;
		}
		i = -1;
		while (++i < 4)
		{
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
			tetris->current->coord[i].x--;
			load_current_tetromino(tetris);
		}
	}
	else if (IsKeyPressedRepeat(KEY_RIGHT))
	{
		while (++i < 4)
		{
			if (!is_valid_position(tetris, tetris->current->coord[i].x + 1, tetris->current->coord[i].y))
				return ;
		}
		i = -1;
		while (++i < 4)
		{
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
			tetris->current->coord[i].x++;
			load_current_tetromino(tetris);
		}
	}
	else if (IsKeyPressed(KEY_DOWN))
	{
		while (++i < 4)
		{
			if (!is_valid_position(tetris, tetris->current->coord[i].x, tetris->current->coord[i].y + 1))
				return ;
		}
		i = -1;
		while (++i < 4)
		{
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
			tetris->current->coord[i].y++;
			load_current_tetromino(tetris);
		}
	}
	else if (IsKeyPressedRepeat(KEY_DOWN))
	{
		while (++i < 4)
		{
			if (!is_valid_position(tetris, tetris->current->coord[i].x, tetris->current->coord[i].y + 1))
				return ;
		}
		i = -1;
		while (++i < 4)
		{
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
			tetris->current->coord[i].y++;
			load_current_tetromino(tetris);
		}
	}
	else if (IsKeyPressed(KEY_SPACE))
	{
		while (++i < 4)
		{
			if (!is_valid_position(tetris, tetris->current->coord[i].x, tetris->current->coord[i].y + 1))
				return ;
		}
		i = -1;
		while (++i < 4)
		{
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
			tetris->current->coord[i].y++;
			load_current_tetromino(tetris);
		}
	}
}
