#include "../include/tetris.h"


bool	is_tetromino_coord(t_tetromino *tetromino, t_coord coord)
{
	int	i = -1;
	
	while (++i < 4)
	{
		if (tetromino->coord[i].x == coord.x && tetromino->coord[i].y == coord.y)
		return (true);
	}
	return (false);
}

bool is_valid_position(t_tetris *tetris, int x, int y)
{
	if (x < 0 || x >= 12 || y < 0 || y >= 22)
		return (false);
	if (tetris->map[y][x] != EMPTY && !is_tetromino_coord(tetris->current, (t_coord){x, y}))
		return (false);
	return (true);
}
