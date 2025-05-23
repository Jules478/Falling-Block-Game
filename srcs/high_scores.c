#include "../include/tetris.h"

void	fetch_high_scores(t_tetris *tetris)
{
	int	fd;
	char *line;
	int	i = -1;

	fd = open("include/highscores.txt", O_RDONLY);
	if (errno = ENOENT)
	{
		tetris->highscores = NULL;
		return ;
	}
	else
		exit (-1);
	line = get_next_line(fd);
	if (!line)
	{
		tetris->highscores = NULL;
		return ;
	}
	tetris->highscores = malloc(7 * sizeof(char *));
	if (!tetris->highscores)
		exit(-4);
	while (line)
	{
		tetris->highscores[++i] = line;
		line = get_next_line(fd);
	}
	tetris->highscores[++i] = NULL;
	close(fd);
}

void	add_high_score(t_tetris *tetris)
{
	int	fd;
	int	i = -1;

	fd = open("include/highscores.txt", O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit (-1);
	if (tetris->highscores)
	{
		while (i < 6 && tetris->highscores[++i])
		{
			if (tetris->score_int > atoi(tetris->highscores[i]))
				dprintf(fd, "%d\n", tetris->score_int);
			else
				dprintf(fd, "%s\n", tetris->highscores[i]);
		}
	}
	else
		dprintf(fd, "%d\n", tetris->score_int);
	close(fd);
}