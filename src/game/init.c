#include "so_long.h"

t_game *init_game()
{
	t_game *game;

	game = (t_game *)malloc(sizeof(t_game));
	if(!game)
		catch_exception(12, 0);
	game->mlx = init_mlx();
	game->map = init_map();
	if(!game->mlx || !game->map)
	{
		free(game);
		free(game->mlx);
		free(game->map);
		catch_exception(12, 0);
	}
	return (game);
}

t_mlx *init_mlx()
{
	t_mlx *mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if(!mlx)
		return (NULL);
	mlx->mlx = NULL;
	mlx->win = NULL;

	return (mlx);
}

t_map *init_map()
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	if(!map)
		return (NULL);
	map->map = NULL;
	map->x = 0;
	map->y = 0;
	map->coins = 0;
	map->player[0] = 0;
	map->player[1] = 0;
	map->enemy[0] = 0;
	map->enemy[1] = 0;
	map->exit[0] = 0;
	map->exit[1] = 0;

	return (map);
}