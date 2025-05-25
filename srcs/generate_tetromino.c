#include "../include/tetris.h"

void shuffle_bag(int *bag, int size)
{
	int i = size;
	int	j;
	int	temp;

	while (--i > 0)
	{
		j = rand() % (i + 1);
		temp = bag[i];
		bag[i] = bag[j];
		bag[j] = temp;
	}
}

void create_tetromino(t_tetris *tetris, t_tetromino *tetromino)
{
	static int queue[7];
	static int index = 7;
	int	i = -1;

	if (index == 7)
	{
		while (++i < 7)
			queue[i] = i + 1;
		shuffle_bag(queue, 7);
		index = 0;
		tetris->queue = queue;
	}
	tetromino->type = queue[index++];
	tetromino->colour = tetromino_colours[tetromino->type];
}

void	draw_current_tetromino(t_tetris *tetris)
{
	if (tetris->current->type == T_PIECE)
	{
		tetris->current->coord[0].x = 5;
		tetris->current->coord[0].y = 2;
		tetris->current->coord[1].x = 4;
		tetris->current->coord[1].y = 2;
		tetris->current->coord[2].x = 6;
		tetris->current->coord[2].y = 2;
		tetris->current->coord[3].x = 5;
		tetris->current->coord[3].y = 1;
	}
	else if (tetris->current->type == O_PIECE)
	{
		tetris->current->coord[0].x = 6;
		tetris->current->coord[0].y = 2;
		tetris->current->coord[1].x = 5;
		tetris->current->coord[1].y = 2;
		tetris->current->coord[2].x = 6;
		tetris->current->coord[2].y = 1;
		tetris->current->coord[3].x = 5;
		tetris->current->coord[3].y = 1;
	}
	else if (tetris->current->type == J_PIECE)
	{
		tetris->current->coord[0].x = 5;
		tetris->current->coord[0].y = 2;
		tetris->current->coord[1].x = 4;
		tetris->current->coord[1].y = 2;
		tetris->current->coord[2].x = 6;
		tetris->current->coord[2].y = 2;
		tetris->current->coord[3].x = 4;
		tetris->current->coord[3].y = 1;
	}
	else if (tetris->current->type == L_PIECE)
	{
		tetris->current->coord[0].x = 5;
		tetris->current->coord[0].y = 2;
		tetris->current->coord[1].x = 4;
		tetris->current->coord[1].y = 2;
		tetris->current->coord[2].x = 6;
		tetris->current->coord[2].y = 2;
		tetris->current->coord[3].x = 6;
		tetris->current->coord[3].y = 1;
	}
	else if (tetris->current->type == S_PIECE)
	{
		tetris->current->coord[0].x = 5;
		tetris->current->coord[0].y = 2;
		tetris->current->coord[1].x = 4;
		tetris->current->coord[1].y = 2;
		tetris->current->coord[2].x = 6;
		tetris->current->coord[2].y = 1;
		tetris->current->coord[3].x = 5;
		tetris->current->coord[3].y = 1;
	}
	else if (tetris->current->type == Z_PIECE)
	{
		tetris->current->coord[0].x = 5;
		tetris->current->coord[0].y = 2;
		tetris->current->coord[1].x = 6;
		tetris->current->coord[1].y = 2;
		tetris->current->coord[2].x = 4;
		tetris->current->coord[2].y = 1;
		tetris->current->coord[3].x = 5;
		tetris->current->coord[3].y = 1;
	}
	else if (tetris->current->type == I_PIECE)
	{
		tetris->current->coord[0].x = 4;
		tetris->current->coord[0].y = 1;
		tetris->current->coord[1].x = 5;
		tetris->current->coord[1].y = 1;
		tetris->current->coord[2].x = 6;
		tetris->current->coord[2].y = 1;
		tetris->current->coord[3].x = 7;
		tetris->current->coord[3].y = 1;
	}
}
