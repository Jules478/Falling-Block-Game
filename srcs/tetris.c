#include "../include/tetris.h"

void	close_game(t_tetris *tetris, int ex, bool start)
{
	if (tetris->current)
		free(tetris->current);
	if (tetris->next)
		free(tetris->next);
	if (tetris->held)
		free(tetris->held);
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

	srand(time(NULL));
	init_game(&tetris);
	SetTargetFPS(60);
	create_window(&tetris);
	InitWindow(tetris.width, tetris.height, "Tetris");
	draw_controls(&tetris);
	create_tetromino(tetris.current);
	create_tetromino(tetris.next);
	while(!WindowShouldClose())
	{
		BeginDrawing();
		draw_ui(&tetris);
		EndDrawing();
	}
	close_game(&tetris, 0, true);
	return (0);
}
