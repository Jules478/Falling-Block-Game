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
# include <math.h>
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
	bool detected;
}	t_tetromino;

typedef struct s_tetris
{
	int map[22][12];
	t_tetromino *current;
	t_tetromino *next;
	t_tetromino *held;
	Texture2D controls;
	float	speed;
	int	height;
	int	width;
	int	size;
	int	tet_size;
	bool	hold;
	bool	locked;
	int prev;
	int	score_int;
	char *score_str;
	int level_int;
	char *level_str;
	int	level_prog;
	int	btb;
}	t_tetris;

/////////////// FUNCTIONS ///////////////

void	close_game(t_tetris *tetris, int ex, bool start);
void	init_game(t_tetris *tetris);
void	create_window(t_tetris *tetris);
void	draw_controls(t_tetris *tetris);
void	draw_ui(t_tetris *tetris);
void	create_tetromino(t_tetris *tetris, t_tetromino *tetromino);
void	draw_current_tetromino(t_tetris *tetris);
void	draw_game_state(t_tetris *tetris);
void	load_current_tetromino(t_tetris *tetris);
void	advance_one_stage(t_tetris *tetris);
t_tetromino *allocate_tetromino(t_tetris *tetris);
void	detect_input(t_tetris *tetris);
bool is_valid_position(t_tetris *tetris, int x, int y);
void	draw_held_tetromino(t_tetris *tetris);
void	check_for_clears(t_tetris *tetris);
void	hard_drop(t_tetris *tetris);
void	check_orientation(t_tetris *tetris);
bool	wall_collision(t_tetris *tetris, int x, int y);
bool	floor_collision(t_tetris *tetris, int x, int y);
int	manage_collision(t_tetris *tetris, t_coord *coord);
bool is_valid_position_go(t_tetris *tetris, int x, int y);
char *tet_itoa(t_tetris *tetris, int x);
void	change_speed(t_tetris *tetris);

#endif