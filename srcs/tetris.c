#include "../include/tetris.h"

void	close_game(int ex)
{
	endwin();
	exit(ex);
}

int	main()
{
	t_tetris tetris;

	init_game(&tetris);
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	close_game(0);
	return (0);
}
