#include "../include/tetris.h"

void	draw_high_scores(t_tetris *tetris)
{
	int	i = -1;

	if (!tetris->highscores_list)
		return ;
	while (tetris->highscores[++i])
		DrawText(tetris->highscores_list[i], (12 * tetris->size) + 5, ((15 + i) * tetris->size) + 5, tetris->size - 1, WHITE);
}
void split_high_score(t_tetris *tetris)
{
	int	i = -1;
	char **parts = NULL;

	while (tetris->highscores_list[++i])
	{
		parts = ft_bigsplit(tetris->highscores_list[i], ": ");
		if (!parts)
			close_game(tetris, 1, true);
		tetris->highscores[i] = parts[1];
		free(parts[0]);
		free(parts);
		parts = NULL;
	}
}

void	fetch_high_scores(t_tetris *tetris)
{
	int	fd;
	char *line;
	int	i = -1;

	fd = open("include/highscores.txt", O_RDONLY);
	if (errno == ENOENT)
	{
		tetris->highscores_list = NULL;
		return ;
	}
	else if (errno != 0)
		exit (-1);
	line = get_next_line(fd);
	if (!line)
	{
		tetris->highscores_list = NULL;
		return ;
	}
	tetris->highscores_list = malloc(7 * sizeof(char *));
	if (!tetris->highscores_list)
		exit(-4);
	tetris->highscores = malloc(7 * sizeof(char *));
	if (!tetris->highscores)
		exit(-4);
	while (line)
	{
		tetris->highscores_list[++i] = line;
		line = get_next_line(fd);
	}
	tetris->highscores_list[++i] = NULL;
	close(fd);
	split_high_score(tetris);
}

void	add_high_score(t_tetris *tetris, char *full)
{
	int	fd;
	int	i = -1;
	bool saved = false;
	int	j = 6;

	fd = open("include/highscores.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit (-1);
	if (tetris->highscores_list)
	{
		while (tetris->highscores_list[++i] || i < j)
		{
			if (i == j || (!tetris->highscores_list[i] && saved == true))
				break;
			if (!tetris->highscores_list[i] && saved == false)
			{
				dprintf(fd, "%s: %d", full, tetris->score);
				break;
			}
			if (tetris->score > atoi(tetris->highscores[i]) && saved == false)
			{
				saved = true;
				dprintf(fd, "%s: %d", full, tetris->score);
				i--;
				j--;
			}
			else
				dprintf(fd, "%s", tetris->highscores_list[i]);
		}
	}
	else
	{
		dprintf(fd, "%d\n", tetris->score);
	}
	close(fd);
}
