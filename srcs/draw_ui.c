#include "../include/tetris.h"

void	draw_controls(t_tetris *tetris)
{
	Image image = LoadImage("image/controlwhite.png");
	if (!image.data)
		exit (1);
	ImageResize(&image, 20 * tetris->size, 2 * tetris->size);
	tetris->controls = LoadTextureFromImage(image);
	UnloadImage(image);
}

void	draw_next_tetromino(t_tetris *tetris)
{
	if (tetris->next->type == O_PIECE)
	{
		DrawRectangle(14 * tetris->size, 2 * tetris->size, tetris->tet_size, tetris->tet_size, O_COLOUR);
		DrawRectangle(15 * tetris->size, 2 * tetris->size, tetris->tet_size, tetris->tet_size, O_COLOUR);
		DrawRectangle(15 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, O_COLOUR);
		DrawRectangle(14 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, O_COLOUR);
	}
	else if (tetris->next->type == I_PIECE)
	{
		DrawRectangle(13 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, I_COLOUR);
		DrawRectangle(16 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, I_COLOUR);
		DrawRectangle(15 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, I_COLOUR);
		DrawRectangle(14 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, I_COLOUR);
	}
	else if (tetris->next->type == S_PIECE)
	{
		DrawRectangle(15 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, S_COLOUR);
		DrawRectangle(14 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, S_COLOUR);
		DrawRectangle(15 * tetris->size, 2 * tetris->size, tetris->tet_size, tetris->tet_size, S_COLOUR);
		DrawRectangle(16 * tetris->size, 2 * tetris->size, tetris->tet_size, tetris->tet_size, S_COLOUR);
	}	
	else if (tetris->next->type == Z_PIECE)
	{
		DrawRectangle(15 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, Z_COLOUR);
		DrawRectangle(16 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, Z_COLOUR);
		DrawRectangle(15 * tetris->size, 2 * tetris->size, tetris->tet_size, tetris->tet_size, Z_COLOUR);
		DrawRectangle(14 * tetris->size, 2 * tetris->size, tetris->tet_size, tetris->tet_size, Z_COLOUR);
	}
	else if (tetris->next->type == L_PIECE)
	{
		DrawRectangle(15 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, L_COLOUR);
		DrawRectangle(14 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, L_COLOUR);
		DrawRectangle(16 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, L_COLOUR);
		DrawRectangle(16 * tetris->size, 2 * tetris->size, tetris->tet_size, tetris->tet_size, L_COLOUR);
	}
	else if (tetris->next->type == J_PIECE)
	{
		DrawRectangle(15 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, J_COLOUR);
		DrawRectangle(14 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, J_COLOUR);
		DrawRectangle(16 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, J_COLOUR);
		DrawRectangle(14 * tetris->size, 2 * tetris->size, tetris->tet_size, tetris->tet_size, J_COLOUR);
	}
	else if (tetris->next->type == T_PIECE)
	{
		DrawRectangle(14 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, T_COLOUR);
		DrawRectangle(15 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, T_COLOUR);
		DrawRectangle(16 * tetris->size, 3 * tetris->size, tetris->tet_size, tetris->tet_size, T_COLOUR);
		DrawRectangle(15 * tetris->size, 2 * tetris->size, tetris->tet_size, tetris->tet_size, T_COLOUR);
	}
}

void	draw_ui(t_tetris *tetris)
{
	int	i;
	int	j;

	ClearBackground(BLACK);
	i = -1;
	while (++i < 22)
	{
		j = -1;
		while (++j < 12)
		{
			if (tetris->map[i][j] == WALL)
				DrawRectangle(j * tetris->size, i * tetris->size, tetris->size, tetris->size, GRAY);
		}
	}
	DrawRectangle(12 * tetris->size, 0 * tetris->size, 10 * tetris->size, 22 * tetris->size, GRAY);
	DrawRectangle(12 * tetris->size, 1 * tetris->size, 7 * tetris->size, 9 * tetris->size, BLACK);
	DrawRectangle(12 * tetris->size, 11 * tetris->size, 7 * tetris->size, 10 * tetris->size, BLACK);
	DrawRectangle(12 * tetris->size, 5 * tetris->size, 7 * tetris->size, 1 * tetris->size, GRAY);
	DrawTexture(tetris->controls, 0 * tetris->size, 22 * tetris->size, WHITE);
	DrawText("Next", (12 * tetris->size) + 5, (1 * tetris->size) + 5, tetris->size - 1, WHITE);
	DrawText("Held", (12 * tetris->size) + 5, (6 * tetris->size) + 5, tetris->size - 1, WHITE);
	DrawText("Level:", (12 * tetris->size) + 5, (11 * tetris->size) + 5, tetris->size - 1, WHITE);
	DrawText(tetris->level_str, (15 * tetris->size) + 5, (11 * tetris->size) + 5, tetris->size - 1, WHITE);
	DrawText("Score:", (12 * tetris->size) + 5, (12 * tetris->size) + 5, tetris->size - 1, WHITE);
	DrawText(tetris->score_str, (15 * tetris->size) + 5, (12 * tetris->size) + 5, tetris->size - 1, WHITE);
	DrawRectangle(12 * tetris->size, 13 * tetris->size, 7 * tetris->size, 1 * tetris->size, GRAY);
	DrawText("High Scores:", (12 * tetris->size) + 5, (14 * tetris->size) + 5, tetris->size - 1, WHITE);
	
	
	draw_next_tetromino(tetris);
}
