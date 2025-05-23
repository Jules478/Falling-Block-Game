#include "../include/tetris.h"

void	game_over_screen(t_tetris *tetris)
{
	char	first;
	char	second;
	char	third;
	
	DrawRectangle(3 * tetris->size, 6 * tetris->size, 14 * tetris->size, 8 * tetris->size, LIGHTGRAY);
}

void	grey_out_tetrominos(t_tetris *tetris)
{
	int	i = 0;
	int	j;

	while (++i < 21)
	{
		j = 0;
		while (++j < 11)
			if (tetris->map[i][j] != EMPTY)
				DrawRectangle(j * tetris->size, i * tetris->size, tetris->tet_size, tetris->tet_size, GRAY);
	}
}
