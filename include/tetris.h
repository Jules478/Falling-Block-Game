#ifndef TETRIS_H
# define TETRIS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <curses.h>
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>

# define I_COLOUR "\e[0;36m"
# define O_COLOUR "\e[0;33m"
# define L_COLOUR "\e[0;37m"
# define J_COLOUR "\e[0;34m"
# define S_COLOUR "\e[0;32m"
# define Z_COLOUR "\e[0;31m"
# define T_COLOUR "\e[0;35m"
# define RESET "\e[0m"

# define EMPTY 0
# define I_PIECE 1
# define O_PIECE 2
# define L_PIECE 3
# define J_PIECE 4
# define S_PIECE 5
# define Z_PIECE 6
# define T_PIECE 7
# define TOP_WALL 8
# define SIDE_WALL 9
# define CORNER 10

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_tile
{
	t_coord pos;
	int type;
	char *colour;
}	t_tile;

typedef struct s_tetris
{
	t_tile tile[22][12];
	t_coord active_piece[5];
	t_coord next_piece[5];

}	t_tetris;

/////////////// FUNCTIONS ///////////////

void	close_game(int ex);
void	init_game(t_tetris *tetris);


#endif