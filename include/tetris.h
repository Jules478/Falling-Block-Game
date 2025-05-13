#ifndef TETRIS_H
# define TETRIS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>
# include "raylib.h"

# define I_COLOUR SKYBLUE
# define O_COLOUR YELLOW
# define L_COLOUR ORANGE
# define J_COLOUR BLUE
# define S_COLOUR GREEN
# define Z_COLOUR RED
# define T_COLOUR PURPLE



# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 1000

typedef enum types
{
	EMPTY,
	I_PIECE,
	O_PIECE,
	L_PIECE,
	J_PIECE,
	S_PIECE,
	Z_PIECE,
	T_PIECE 
} t_types;

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

typedef struct s_tetromino
{
	int	type;
	t_coord coord[4];
	char *colour;
}	t_tetromino;

typedef struct s_tetris
{
	t_tile tile[22][12];
	t_coord active_piece[5];
	t_coord next_piece[5];
	int	speed;
}	t_tetris;

/////////////// FUNCTIONS ///////////////

void	close_game(int ex);
void	init_game(t_tetris *tetris);


#endif