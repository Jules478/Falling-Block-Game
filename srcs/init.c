#include "../include/tetris.h"

void	init_game(t_tetris *tetris)
{
	int	i = -1;
	int	j;

	while (++i < 22)
	{
		j = -1;
		while (++j < 12)
		{
			tetris->tile[i][j].pos.x = j;
			tetris->tile[i][j].pos.y = i;
			if ((i == 0 && j == 0) || (i == 0 && j == 11) || (i == 21 && j == 11) || (i == 21 && j == 0))
				tetris->tile[i][j].type = CORNER;
			else if (i == 0 || i == 21)
				tetris->tile[i][j].type = TOP_WALL;
			else if (j == 0 || j == 11)
				tetris->tile[i][j].type = SIDE_WALL;
			else
				tetris->tile[i][j].type = EMPTY;
			tetris->tile[i][j].colour = NULL;
		}
	}
}
