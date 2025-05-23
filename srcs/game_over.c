#include "../include/tetris.h"

void	export_name_to_score(t_tetris *tetris, char *name)
{
	add_high_score(tetris, name);
	close_game(tetris, 0, true);
}

int	write_name(char *name)
{
	static int	i = 0;
	int c = 0;

	c = GetKeyPressed();
	if (!c)
		return (i);
	if (c == KEY_BACKSPACE)
	{
		if (i > 0)
		{
			i--;
			name[i] = 0;
			return (i);
		}
		return (i);
	}
	if (c == KEY_ENTER)
	{
		if (i == 3)
			return (-1);
		return (i);
	}
	if (i == 3)
		return (i);
	name[i] = c;
	i++;
	return (i);
}

void	game_over_screen(t_tetris *tetris)
{
	int	margin = tetris->size / 10;
	char score[20];
	int len = intlen(tetris->score_int);
	int	i = -1;
	static char	name[4];
	int	c;

	DrawRectangle(3 * tetris->size, 6 * tetris->size, 14 * tetris->size, 8 * tetris->size, LIGHTGRAY);
	DrawRectangle((3 * tetris->size) + margin, (6 * tetris->size) + margin, (14 * tetris->size) - (margin * 2) - 1, (8 * tetris->size) - (margin * 2) - 1, BLACK);
	DrawText("Game Over", (7 * tetris->size) + 5 + (tetris->size / 2), (6 * tetris->size) + 5, tetris->size - 1, WHITE);
	snprintf(score, sizeof(score), "Your Score: %d", tetris->score_int);
	DrawText(score, ((7 - (len / 2)) * tetris->size) + 5, (8 * tetris->size) + 5, tetris->size - 1, WHITE);
	if (tetris->highscores)
	{
		while (tetris->highscores[++i])
		{
			if (tetris->score_int > atoi(tetris->highscores[i]))
			{
				DrawText("New High Score!", (6 * tetris->size) + 5, (9 * tetris->size) + 5, tetris->size - 1, WHITE);
				DrawText("Enter Name:", (7 * tetris->size) + 5, (10 * tetris->size) + 5, tetris->size - 1, WHITE);
				c = write_name(name);
				if (c > 0)
				{
					DrawText(name, (9 * tetris->size) + 5, (11 * tetris->size) + 5, tetris->size - 1, WHITE);
				}
				else if (c == -1)
					export_name_to_score(tetris, name);
			}
		}
	}
}

void	grey_out_tetrominos(t_tetris *tetris)
{
	int	i = 0;
	int	j;

	while (++i < 21)
	{
		j = 0;
		while (++j < 11)
			if (tetris->map[i][j] != EMPTY)
				DrawRectangle(j * tetris->size, i * tetris->size, tetris->tet_size, tetris->tet_size, DARKGRAY);
	}
}
