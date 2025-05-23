#include "../include/tetris.h"

void	draw_high_scores(t_tetris *tetris)
{
	int	i = -1;

	if (!tetris->highscores)
		return ;
	while (tetris->highscores[++i])
		DrawText(tetris->highscores[i], (12 * tetris->size) + 5, ((15 + i) * tetris->size) + 5, tetris->size - 1, WHITE);
}

void	fetch_high_scores(t_tetris *tetris)
{
	int	fd;
	char *line;
	int	i = -1;

	fd = open("include/highscores.txt", O_RDONLY);
	if (errno == ENOENT)
	{
		tetris->highscores = NULL;
		return ;
	}
	else if (errno != 0)
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
	bool saved = false;
	int	j = 6;

	fd = open("include/highscores.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit (-1);
	if (tetris->highscores)
	{
		while (tetris->highscores[++i] || i < j)
		{
			if (i == j || (!tetris->highscores[i] && saved == true))
				break;
			if (!tetris->highscores[i] && saved == false)
			{
				dprintf(fd, "%d\n", tetris->score_int);
				break;
			}
			if (tetris->score_int > atoi(tetris->highscores[i]) && saved == false)
			{
				saved = true;
				dprintf(fd, "%d\n", tetris->score_int);
				i--;
				j--;
			}
			else
				dprintf(fd, "%s", tetris->highscores[i]);
		}
	}
	else
	{
		dprintf(fd, "%d\n", tetris->score_int);
	}
	close(fd);
}
