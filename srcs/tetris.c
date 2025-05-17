#include "../include/tetris.h"

void	close_game(t_tetris *tetris, int ex, bool start)
{
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
	int	frames = 1;

	srand(time(NULL));
	init_game(&tetris);
	SetTargetFPS(60);
	create_window(&tetris);
	InitWindow(tetris.width, tetris.height, "Tetris");
	draw_controls(&tetris);
	create_tetromino(tetris.current);
	create_tetromino(tetris.next);
	draw_current_tetromino(&tetris);
	load_current_tetromino(&tetris);
	while(!WindowShouldClose())
	{
		BeginDrawing();
		draw_ui(&tetris);
		draw_game_state(&tetris);
		draw_held_tetromino(&tetris);
		detect_input(&tetris);
		if (frames % tetris.speed == 0)
			advance_one_stage(&tetris);
		frames++;
		EndDrawing();
	}
	close_game(&tetris, 0, true);
	return (0);
}
