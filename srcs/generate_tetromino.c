#include "../include/tetris.h"

void	create_tetromino(t_tetromino *tetromino)
{
	int	select;

	select = rand() % 7 + 1;
	if (select == I_PIECE)
		tetromino->colour = I_COLOUR;
	else if (select == O_PIECE)
		tetromino->colour = O_COLOUR;
	else if (select == L_PIECE)
		tetromino->colour = L_COLOUR;
	else if (select == J_PIECE)
		tetromino->colour = J_COLOUR;
	else if (select == S_PIECE)
		tetromino->colour = S_COLOUR;
	else if (select == Z_PIECE)
		tetromino->colour = Z_COLOUR;
	tetromino->type = select;
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
		tetris->current->collision = 3;
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
		tetris->current->collision = 2;
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
		tetris->current->collision = 3;
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
		tetris->current->collision = 3;
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
		tetris->current->collision = 3;
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
		tetris->current->collision = 3;
	}
	else if (tetris->current->type == I_PIECE)
	{
		tetris->current->coord[0].x = 6;
		tetris->current->coord[0].y = 1;
		tetris->current->coord[1].x = 5;
		tetris->current->coord[1].y = 1;
		tetris->current->coord[2].x = 4;
		tetris->current->coord[2].y = 1;
		tetris->current->coord[3].x = 7;
		tetris->current->coord[3].y = 1;
		tetris->current->collision = 4;
	}
}
