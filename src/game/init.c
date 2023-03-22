#include "so_long.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		catch_exception(12, 0);
	game->mlx = init_mlx();
	game->map = init_map();
	game->status = init_status();
	if (!game->mlx || !game->map || !game->status)
	{
		free(game->mlx);
		free(game->map);
		free(game->status);
		free(game);
		catch_exception(12, 0);
	}
	return (game);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx = NULL;
	mlx->win = NULL;
	return (mlx);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL;
	map->x = 0;
	map->y = 0;
	map->x_size = 0;
	map->y_size = 0;
	map->coin = 0;
	map->player[0] = 0;
	map->player[1] = 0;
	map->enemy = 0;
	map->exit = 0;
	map->is_exit = 0;
	return (map);
}

t_status	*init_status(void)
{
	t_status	*status;

	status = (t_status *)malloc(sizeof(t_status));
	if (!status)
		return (NULL);
	status->clc_coins = 0;
	status->p = 0;
	status->e = 0;
	status->loop = 0;
	status->is_lose = 0;
	status->loop_lose = 0;
	status->move_counter = 0;
	return (status);
}
