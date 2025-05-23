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
# include "../libft/libft.h"
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

static const Color TETROMINO_COLORS[] =
{
	WALL_COLOUR,
	I_COLOUR,
	O_COLOUR,
	L_COLOUR,
	J_COLOUR,
	S_COLOUR,
	Z_COLOUR,
	T_COLOUR
};

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
	int		type;
	t_coord	*coord;
	Color	colour;
	int		orientation;
	bool	detected;
	int		times_moved;
	bool	hard_drop;
	bool	on_ground;
}	t_tetromino;

typedef struct s_tetris
{
	int 		map[22][12];
	t_tetromino	*current;
	t_tetromino	*next;
	t_tetromino	*held;
	Texture2D	controls;
	float		speed;
	int			height;
	int			width;
	int			size;
	int			tet_size;
	bool		hold;
	bool		locked;
	int			prev;
	int			score;
	int			level;
	int			level_prog;
	int			btb;
	float	mrl_delay;
	float	time_since_last;
	float delta_time;
	int	*queue;
	char	**highscores;
	char **highscores_list;
	bool	game_over;
	bool	paused;
}	t_tetris;

/////////////// FUNCTIONS ///////////////

void		close_game(t_tetris *tetris, int ex, bool start);
void		init_game(t_tetris *tetris);
void		create_window(t_tetris *tetris);
void		draw_controls(t_tetris *tetris);
void		draw_ui(t_tetris *tetris);
void		create_tetromino(t_tetris *tetris, t_tetromino *tetromino);
void		draw_current_tetromino(t_tetris *tetris);
void		draw_game_state(t_tetris *tetris);
void		load_current_tetromino(t_tetris *tetris);
void		advance_one_stage(t_tetris *tetris);
t_tetromino	*allocate_tetromino(t_tetris *tetris);
void		detect_input(t_tetris *tetris);
bool		 is_valid_position(t_tetris *tetris, int x, int y);
void		draw_held_tetromino(t_tetris *tetris);
void		check_for_clears(t_tetris *tetris);
void		hard_drop(t_tetris *tetris);
void		rotate_tetromino(t_tetris *tetris);
bool		check_collision(t_tetris *tetris, int x, int y);
int			manage_collision(t_tetris *tetris, t_coord *coord);
void		change_speed(t_tetris *tetris);
void		lock_tetromino(t_tetris *tetris);
void		check_game_over(t_tetris *tetris);
void		draw_ghost(t_tetris *tetris);
bool		is_tetromino_coord(t_tetromino *tetromino, t_coord coord);
void		check_lock(t_tetris *tetris);
void		fetch_high_scores(t_tetris *tetris);
void		add_high_score(t_tetris *tetris, char *full);
void		draw_high_scores(t_tetris *tetris);
void		grey_out_tetrominos(t_tetris *tetris);
void		game_over_screen(t_tetris *tetris);
void		check_pause(t_tetris *tetris);
int			intlen(int num);

#endif