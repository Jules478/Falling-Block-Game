#include "../include/tetris.h"

void	init_game(t_tetris *tetris)
{
	int	i = -1;
	int	j;

	while (++i < 20)
	{
		j = -1;
		while (++j < 10)
			tetris->map[i][j] = EMPTY;
	}
}
