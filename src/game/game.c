#include "so_long.h"

void game_controller(t_game *game)
{
	start_mlx(game);
}

void start_mlx(t_game *game)
{
	size_t width_size;
	size_t height_size;

	game->mlx->mlx = mlx_init();
	width_size = game->map->x_size * HEIGHT;
	height_size = game->map->y_size * WIDTH;
	game->mlx->win = mlx_new_window(game->mlx->mlx, width_size, height_size, GAME_NAME);
	mlx_loop_hook(game->mlx->mlx, draw_map, game);
	// draw_map(game);
	mlx_loop(game->mlx->mlx);
}

int draw_map(t_game *game)
{
	void *sprite;
	char **map;
	int i;
	int j;
	int w = 64;
	int h = 64;

	mlx_clear_window(game->mlx->mlx, game->mlx->win);
	map = game->map->map;
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == WALL_FLAG)
				sprite = mlx_xpm_file_to_image(game->mlx->mlx, "./textures/other/wall.xpm", &w, &h);
			else if(map[i][j] == PLAYER_FLAG)
				sprite = mlx_xpm_file_to_image(game->mlx->mlx, "./textures/player/1.xpm", &w, &h);
			else if(map[i][j] == ENEMY_FLAG)
				sprite = mlx_xpm_file_to_image(game->mlx->mlx, "./textures/enemy/1.xpm", &w, &h);
			else if(map[i][j] == COIN_FLAG)
				sprite = mlx_xpm_file_to_image(game->mlx->mlx, "./textures/other/coin.xpm", &w, &h);
			else
				sprite = 0;
			if(sprite)
				mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, sprite, j * WIDTH, i * HEIGHT);
			j++;
		}
		i++;
	}
	return (0);
}