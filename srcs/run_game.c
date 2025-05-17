#include "../include/tetris.h"

void	check_game_over(t_tetris *tetris)
{
	int	i = -1;

	while (++i < 4)
	{
		if (!is_valid_position_go(tetris, tetris->current->coord[i].x, tetris->current->coord[i].y))
			close_game(tetris, 0, true);
	}
}

void	advance_one_stage(t_tetris *tetris)
{
	int	i = -1;
	bool	collision = false;

	if (tetris->current->detected == true)
	{
		if (tetris->locked == true)
		{
			free(tetris->current->coord);
			free(tetris->current);
			check_for_clears(tetris);
			tetris->current = tetris->next;
			tetris->next = allocate_tetromino(tetris);
			create_tetromino(tetris, tetris->next);
			draw_current_tetromino(tetris);
			check_game_over(tetris);
			load_current_tetromino(tetris);
			tetris->hold = false;
			return ;
		}
		tetris->current->detected = false;
		tetris->locked = true;
		return ;
	}
		while (++i < 4)
		{
			if (!is_valid_position(tetris, tetris->current->coord[i].x, tetris->current->coord[i].y + 1))
			{
				collision = true;
				tetris->current->detected = true;
				tetris->locked = true;
				break ;
			}
		}
		i = -1;
		while (++i < 4 && collision == false)
		{
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
			tetris->current->coord[i].y++;				
		}
	load_current_tetromino(tetris);
}

void	swap_held(t_tetris *tetris)
{
	t_tetromino *temp;
	int	i = -1;

	if (tetris->held)
	{
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		temp = tetris->held;
		tetris->held = tetris->current;
		tetris->current = temp;
		draw_current_tetromino(tetris);
		check_game_over(tetris);
		load_current_tetromino(tetris);
		draw_held_tetromino(tetris);
	}
	else
	{
		temp = allocate_tetromino(tetris);
		temp->type = tetris->current->type;
		temp->colour = tetris->current->colour;
		tetris->held = temp;
		draw_held_tetromino(tetris);
		while (++i < 4)
			tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = EMPTY;
		free(tetris->current->coord);
		free(tetris->current);
		tetris->current = tetris->next;
		tetris->next = allocate_tetromino(tetris);
		create_tetromino(tetris, tetris->next);
		draw_current_tetromino(tetris);
		check_game_over(tetris);
		load_current_tetromino(tetris);
	}
	tetris->hold = true;
}

void	detect_input(t_tetris *tetris)
{
	int	i = -1;
	if (IsKeyPressed(KEY_LEFT) && tetris->current->detected == false)
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
	else if (IsKeyPressed(KEY_RIGHT) && tetris->current->detected == false)
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
	else if (IsKeyPressedRepeat(KEY_LEFT) && tetris->current->detected == false)
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
	else if (IsKeyPressedRepeat(KEY_RIGHT) && tetris->current->detected == false)
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
	else if (IsKeyPressed(KEY_DOWN) && tetris->current->detected == false)
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
	else if (IsKeyPressedRepeat(KEY_DOWN) && tetris->current->detected == false)
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
	else if (IsKeyPressed(KEY_SPACE) && tetris->current->detected == false)
	{
		hard_drop(tetris);
		tetris->locked = true;
	}
	else if (IsKeyPressed(KEY_C) && tetris->current->detected == false)
	{
		if (tetris->hold == false)
			swap_held(tetris);
	}
	else if (IsKeyPressed(KEY_UP) && tetris->current->detected == false)
	{
		check_orientation(tetris);
	}
}

void	clear_line(t_tetris *tetris, int i)
{
	int	j;
	while (i > 1)
	{
		j = 0;
		while (++j < 11)
		{
			tetris->map[i][j] = tetris->map[i - 1][j];
		}
		i--;
	}
	j = 0;
	while (++j < 11)
		tetris->map[1][j] = EMPTY;
	draw_game_state(tetris);
}

void	check_for_clears(t_tetris *tetris)
{
	int	count = 0;
	int	i = 0;
	int	j;
	int	filled;

	while (++i < 21)
	{
		j = 0;
		filled = 0;
		while (++j < 11)
		{
			if (tetris->map[i][j] != EMPTY)
				filled++;
			if (filled == 10)
			{
				clear_line(tetris, i);
				count++;
				i--;
			}
		}
	}
	if (count == 1)
	{
		tetris->score_int += (100 * tetris->level_int);
		tetris->score_str = tet_itoa(tetris, tetris->score_int);
		tetris->btb = 0;
	}
	else if (count == 2)
	{
		tetris->score_int += (300 * tetris->level_int);
		tetris->score_str = tet_itoa(tetris, tetris->score_int);
		tetris->btb = 0;
	}
	else if (count == 3)
	{
		tetris->score_int += (500 * tetris->level_int);
		tetris->score_str = tet_itoa(tetris, tetris->score_int);
		tetris->btb = 0;
	}
	else if (count == 4)
	{
		if (tetris->btb == 1)
			tetris->score_int += (1200 * tetris->level_int);
		else
			tetris->score_int += (800 * tetris->level_int);
		tetris->score_str = tet_itoa(tetris, tetris->score_int);
		tetris->btb = 1;
	}
	tetris->level_prog += count;
	if (tetris->level_prog > 9)
	{
		tetris->level_int++;
		tetris->level_str = tet_itoa(tetris, tetris->level_int);
		tetris->level_prog -= 10;
	}
	change_speed(tetris);
}
