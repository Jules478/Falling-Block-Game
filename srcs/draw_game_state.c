#include "../include/tetris.h"

void	draw_held_tetromino(t_tetris *tetris)
{
	if (tetris->held)
	{
		if (tetris->held->type == O_PIECE)
		{
			DrawRectangle(14 * tetris->size, 7 * tetris->size, tetris->tet_size, tetris->tet_size, O_COLOUR);
			DrawRectangle(15 * tetris->size, 7 * tetris->size, tetris->tet_size, tetris->tet_size, O_COLOUR);
			DrawRectangle(15 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, O_COLOUR);
			DrawRectangle(14 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, O_COLOUR);
		}
		else if (tetris->held->type == I_PIECE)
		{
			DrawRectangle(13 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, I_COLOUR);
			DrawRectangle(16 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, I_COLOUR);
			DrawRectangle(15 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, I_COLOUR);
			DrawRectangle(14 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, I_COLOUR);
		}
		else if (tetris->held->type == S_PIECE)
		{
			DrawRectangle(15 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, S_COLOUR);
			DrawRectangle(14 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, S_COLOUR);
			DrawRectangle(15 * tetris->size, 7 * tetris->size, tetris->tet_size, tetris->tet_size, S_COLOUR);
			DrawRectangle(16 * tetris->size, 7 * tetris->size, tetris->tet_size, tetris->tet_size, S_COLOUR);
		}	
		else if (tetris->held->type == Z_PIECE)
		{
			DrawRectangle(15 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, Z_COLOUR);
			DrawRectangle(16 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, Z_COLOUR);
			DrawRectangle(15 * tetris->size, 7 * tetris->size, tetris->tet_size, tetris->tet_size, Z_COLOUR);
			DrawRectangle(14 * tetris->size, 7 * tetris->size, tetris->tet_size, tetris->tet_size, Z_COLOUR);
		}
		else if (tetris->held->type == L_PIECE)
		{
			DrawRectangle(15 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, L_COLOUR);
			DrawRectangle(14 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, L_COLOUR);
			DrawRectangle(16 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, L_COLOUR);
			DrawRectangle(16 * tetris->size, 7 * tetris->size, tetris->tet_size, tetris->tet_size, L_COLOUR);
		}
		else if (tetris->held->type == J_PIECE)
		{
			DrawRectangle(15 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, J_COLOUR);
			DrawRectangle(14 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, J_COLOUR);
			DrawRectangle(16 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, J_COLOUR);
			DrawRectangle(14 * tetris->size, 7 * tetris->size, tetris->tet_size, tetris->tet_size, J_COLOUR);
		}
		else if (tetris->held->type == T_PIECE)
		{
			DrawRectangle(14 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, T_COLOUR);
			DrawRectangle(15 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, T_COLOUR);
			DrawRectangle(16 * tetris->size, 8 * tetris->size, tetris->tet_size, tetris->tet_size, T_COLOUR);
			DrawRectangle(15 * tetris->size, 7 * tetris->size, tetris->tet_size, tetris->tet_size, T_COLOUR);
		}
	}
}

void	load_current_tetromino(t_tetris *tetris)
{
	int	i = -1;
	
	while (++i < 4)
		tetris->map[tetris->current->coord[i].y][tetris->current->coord[i].x] = tetris->current->type;
}

void	draw_game_state(t_tetris *tetris)
{
	int	i = 0;
	int	j;

	while (++i < 21)
	{
		j = 0;
		while (++j < 11)
		{
			if (tetris->map[i][j] == O_PIECE)
				DrawRectangle(j * tetris->size, i * tetris->size, tetris->tet_size, tetris->tet_size, O_COLOUR);
			else if (tetris->map[i][j] == I_PIECE)
				DrawRectangle(j * tetris->size, i * tetris->size, tetris->tet_size, tetris->tet_size, I_COLOUR);
			else if (tetris->map[i][j] == S_PIECE)
				DrawRectangle(j * tetris->size, i * tetris->size, tetris->tet_size, tetris->tet_size, S_COLOUR);
			else if (tetris->map[i][j] == Z_PIECE)
				DrawRectangle(j * tetris->size, i * tetris->size, tetris->tet_size, tetris->tet_size, Z_COLOUR);
			else if (tetris->map[i][j] == L_PIECE)
				DrawRectangle(j * tetris->size, i * tetris->size, tetris->tet_size, tetris->tet_size, L_COLOUR);
			else if (tetris->map[i][j] == J_PIECE)
				DrawRectangle(j * tetris->size, i * tetris->size, tetris->tet_size, tetris->tet_size, J_COLOUR);
			else if (tetris->map[i][j] == T_PIECE)
				DrawRectangle(j * tetris->size, i * tetris->size, tetris->tet_size, tetris->tet_size, T_COLOUR);
		}
	}
}
