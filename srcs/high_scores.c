#include "../include/tetris.h"

void	fetch_high_scores(t_tetris *tetris)
{
	int	fd;
	char *line;
	int	i = -1;
// malloc highscores
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
	while (line)
	{
		tetris->highscores[++i] = line;
		line = get_next_line(fd);
	}
	tetris->highscores[++i] = NULL;
}

void	add_high_score(t_tetris *tetris)
{
	int	fd;

	fd = open("include/highscores.txt", O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit (-1);
	
}