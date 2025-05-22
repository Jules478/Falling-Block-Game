#include "../include/tetris.h"

void	close_game(t_tetris *tetris, int ex, bool start)
{
	int	i = -1;

	if (tetris->highscores)
	{
		while (tetris->highscores[++i])
			free(tetris->highscores[i]);
	}
	free(tetris->level_str);
	free(tetris->score_str);
	if (tetris->current)
	{
		if (tetris->current->coord)
			free(tetris->current->coord);
		free(tetris->current);
	}
	if (tetris->next)
	{
		if (tetris->next->coord)
			free(tetris->next->coord);
		free(tetris->next);
	}
	if (tetris->held)
	{
		if (tetris->held->coord)
			free(tetris->held->coord);
		free(tetris->held);
	}
	if (start == true)
	{
		UnloadTexture(tetris->controls);
		CloseWindow();
	}
	exit(ex);
}


int	main()
{
	t_tetris tetris;
	float time_elapsed = 0.0f;

	srand(time(NULL));
	init_game(&tetris);
	SetTargetFPS(60);
	create_window(&tetris);
	InitWindow(tetris.width, tetris.height, "Tetris");
	draw_controls(&tetris);
	create_tetromino(&tetris, tetris.current);
	create_tetromino(&tetris, tetris.next);
	draw_current_tetromino(&tetris);
	load_current_tetromino(&tetris);
	while(!WindowShouldClose())
	{
		BeginDrawing();
		draw_ui(&tetris);
		draw_game_state(&tetris);
		draw_held_tetromino(&tetris);
		detect_input(&tetris);
		time_elapsed += tetris.delta_time * 60.0f;
    	if (time_elapsed >= tetris.speed)
		{
			advance_one_stage(&tetris);
			time_elapsed -= tetris.speed;
		}
		tetris.time_since_last += tetris.delta_time * 60.0f;
		check_lock(&tetris);
		EndDrawing();
	}
	close_game(&tetris, 0, true);
	return (0);
}
