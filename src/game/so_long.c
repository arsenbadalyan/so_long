#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		handle_error(1, WRONG_ARGUMENTS);
	game = init_game();
	validate_map(argv[1], game);
	game_controller(game);
	return (0);
}
