#include "so_long.h"

void game_controller(t_game *game)
{
	start_mlx(game);
}

void start_mlx(t_game *game)
{
	size_t width_size;
	size_t height_size;

	game->sprites = (void **)malloc(sizeof(void *) * (game->map->x_size * game->map->y_size));
	game->mlx->mlx = mlx_init();
	width_size = game->map->x_size * HEIGHT;
	height_size = game->map->y_size * WIDTH;
	game->mlx->win = mlx_new_window(game->mlx->mlx, width_size, height_size, GAME_NAME);
	mlx_hook(game->mlx->win, 17, 0, exit_game, game);
	mlx_key_hook(game->mlx->win, pass_key, game);
	mlx_loop_hook(game->mlx->mlx, draw_map, game);
	mlx_loop(game->mlx->mlx);
}

int exit_game(t_game *game)
{
	size_t size;
	size_t i;

	i = 0;
	size = game->map->x_size * game->map->y_size;
	while(i < size)
	{
		if (game->sprites[i])
			mlx_destroy_image(game->mlx->mlx, game->sprites[i]);
		i++;
	}
	mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	free(game->sprites);
	free_game(&game);
	ft_putstr_fd("See you soon!\n", 1);
	exit(1);
}