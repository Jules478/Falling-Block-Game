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
