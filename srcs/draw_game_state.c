#include "../include/tetris.h"

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
