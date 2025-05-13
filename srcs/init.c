#include "../include/tetris.h"

void	init_game(t_tetris *tetris)
{
	int	i = -1;
	int	j;

	while (++i < 20)
	{
		j = -1;
		while (++j < 10)
		{
			tetris->tile[i][j].pos.x = j;
			tetris->tile[i][j].pos.y = i;
			tetris->tile[i][j].type = EMPTY;
			tetris->tile[i][j].colour = NULL;
		}
	}
}
