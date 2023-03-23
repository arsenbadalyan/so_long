#include "so_long.h"

void	fill_map_controller(char **map, t_game *game)
{
	size_t	empty[2];

	empty[0] = 0;
	empty[1] = 0;
	game->map->exit = find_characters(map, game, empty, EXIT_FLAG);
	game->map->coin = find_characters(map, game, empty, COIN_FLAG);
	if (find_characters(map, game, empty, PLAYER_FLAG) != 1
		|| game->map->exit != 1 || !game->map->coin)
	{
		free_double(&map);
		free_game(&game);
		handle_error(1, WRONG_PE_CONF);
	}
	game->map->enemy = find_characters(map, game, empty, ENEMY_FLAG);
	game->map->map = map;
	if (find_game_paths(game))
	{
		free_game(&game);
		handle_error(1, WRONG_WAY_CONF);
	}
}

int	find_characters(char **map, t_game *game, size_t *xy, char find)
{
	size_t	counter;

	counter = 0;
	while (map[xy[1]])
	{
		xy[0] = 0;
		while (map[xy[1]][xy[0]])
		{
			if (!ft_strchr(CORRECT_C, map[xy[1]][xy[0]]))
				return (-1);
			if (map[xy[1]][xy[0]] == find && ++counter
				&& find == PLAYER_FLAG)
			{
				game->map->player[0] = xy[0];
				game->map->player[1] = xy[1];
			}
			xy[0]++;
		}
		xy[1]++;
	}
	xy[0] = 0;
	xy[1] = 0;
	return (counter);
}

int	find_game_paths(t_game *game)
{
	t_map	*temp_map;

	temp_map = init_map();
	if (!temp_map)
		return (1);
	temp_map->map = dup_double(game->map->map, game->map->y_size);
	if (!temp_map->map)
	{
		free(temp_map);
		return (1);
	}
	fill_flood_map(temp_map, game->map->player[0], game->map->player[1]);
	if (game->map->coin != temp_map->coin || game->map->exit != temp_map->exit)
	{
		free_double(&temp_map->map);
		free(temp_map);
		return (1);
	}
	free_double(&temp_map->map);
	free(temp_map);
	return (0);
}

void	fill_flood_map(t_map *map, size_t begin_x, size_t begin_y)
{
	if (begin_x == 0 || begin_y == 0
		|| map->map[begin_y][begin_x] == ENEMY_FLAG
		|| map->map[begin_y][begin_x] == WALL_FLAG
		|| map->map[begin_y][begin_x] == 'H')
		return ;
	if (map->map[begin_y][begin_x] == COIN_FLAG)
		map->coin++;
	if (map->map[begin_y][begin_x] == EXIT_FLAG)
		map->exit++;
	map->map[begin_y][begin_x] = 'H';
	fill_flood_map(map, begin_x - 1, begin_y);
	fill_flood_map(map, begin_x, begin_y - 1);
	fill_flood_map(map, begin_x + 1, begin_y);
	fill_flood_map(map, begin_x, begin_y + 1);
}
