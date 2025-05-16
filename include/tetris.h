#ifndef TETRIS_H
# define TETRIS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>
# include <time.h>
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

typedef enum s_types
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

typedef enum s_orientation
{
	LEFT,
	UP,
	RIGHT,
	DOWN
} t_orientation;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_tetromino
{
	int	type;
	t_coord *coord;
	Color colour;
	int	orientation;
	int	collision;
	bool detected;
}	t_tetromino;

typedef struct s_tetris
{
	int map[22][12];
	t_tetromino *current;
	t_tetromino *next;
	t_tetromino *held;
	Texture2D controls;
	int	speed;
	int	height;
	int	width;
	int	size;
	int	tet_size;
}	t_tetris;

/////////////// FUNCTIONS ///////////////

void	close_game(t_tetris *tetris, int ex, bool start);
void	init_game(t_tetris *tetris);
void	create_window(t_tetris *tetris);
void	draw_controls(t_tetris *tetris);
void	draw_ui(t_tetris *tetris);
void	create_tetromino(t_tetromino *tetromino);
void	draw_current_tetromino(t_tetris *tetris);
void	draw_game_state(t_tetris *tetris);
void	load_current_tetromino(t_tetris *tetris);
void	advance_one_stage(t_tetris *tetris);
t_tetromino *allocate_tetromino(t_tetris *tetris);
void	detect_input(t_tetris *tetris);
bool is_valid_position(t_tetris *tetris, int x, int y);


#endif