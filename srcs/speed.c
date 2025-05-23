#include "../include/tetris.h"

void	change_speed(t_tetris *tetris)
{
	if (tetris->level == 1)
		tetris->speed = 1.0f / 0.01667f;
	else if (tetris->level == 2)
		tetris->speed = 1.0f / 0.02101f;
	else if (tetris->level == 3)
		tetris->speed = 1.0f / 0.026977f;
	else if (tetris->level == 4)
		tetris->speed = 1.0f / 0.035256f;
	else if (tetris->level == 5)
		tetris->speed = 1.0f / 0.04693f;
	else if (tetris->level == 6)
		tetris->speed = 1.0f / 0.06361f;
	else if (tetris->level == 7)
		tetris->speed = 1.0f / 0.0879f;
	else if (tetris->level == 8)
		tetris->speed = 1.0f / 0.1236f;
	else if (tetris->level == 9)
		tetris->speed = 1.0f / 0.1775f;
	else if (tetris->level == 10)
		tetris->speed = 1.0f / 0.2598f;
}
