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
# define WALL_COLOUR GRAY



# define RATIO 24

typedef enum types
{
	EMPTY,
	I_PIECE,
	O_PIECE,
	L_PIECE,
	J_PIECE,
	S_PIECE,
	Z_PIECE,
	T_PIECE,
	WALL
} t_types;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_tetromino
{
	int	type;
	t_coord coord[4];
	char *colour;
}	t_tetromino;

typedef struct s_tetris
{
	int map[22][12];
	t_tetromino *current;
	t_tetromino *next;
	Texture2D controls;
	int	speed;
	int	height;
	int	width;
	int	size;
	int	tet_size;
}	t_tetris;

/////////////// FUNCTIONS ///////////////

void	close_game(int ex);
void	init_game(t_tetris *tetris);
void	create_window(t_tetris *tetris);
void	draw_controls(t_tetris *tetris);


#endif