#include "so_long.h"

int	pass_key(int key, t_game *game)
{
	size_t	xy[2];
	char	**map;

	if (game->status->is_lose)
		return (1);
	map = game->map->map;
	xy[0] = game->map->player[0];
	xy[1] = game->map->player[1];
	if (key == LEFT_KEY || key == LEFT_ARROW)
		xy[0] -= 1;
	else if (key == RIGHT_KEY || key == RIGHT_ARROW)
		xy[0] += 1;
	else if (key == UP_KEY || key == UP_ARROW)
		xy[1] -= 1;
	else if (key == BOTTOM_KEY || key == BOTTOM_ARROW)
		xy[1] += 1;
	else if (key == ESC_KEY)
		exit_game(game);
	else
		return (1);
	do_move(game, map, xy[0], xy[1]);
	return (0);
}

void	do_move(t_game *game, char **map, int x, int y)
{
	if (ft_strchr(HAVE_ACCESS, map[y][x]))
	{
		if (!game->map->is_exit)
			map[game->map->player[1]][game->map->player[0]] = SPACE_FLAG;
		else
			map[game->map->player[1]][game->map->player[0]] = EXIT_FLAG;
		game->map->is_exit = 0;
		if (map[y][x] == COIN_FLAG)
			game->status->clc_coins++;
		else if (map[y][x] == EXIT_FLAG
				&& game->map->coin == game->status->clc_coins)
			exit_game(game);
		else if (map[y][x] == EXIT_FLAG)
			game->map->is_exit = 1;
		map[y][x] = PLAYER_FLAG;
	}
	else if (map[y][x] == ENEMY_FLAG)
		player_lose(game, map, x, y);
	else
		return ;
	game->map->player[0] = x;
	game->map->player[1] = y;
	game->status->move_counter += 1;
}

void	player_lose(t_game *game, char **map, int x, int y)
{
	map[game->map->player[1]][game->map->player[0]] = SPACE_FLAG;
	game->map->player[0] = x;
	game->map->player[1] = y;
	map[y][x] = LOSE_FLAG;
	game->status->move_counter += 1;
	game->status->is_lose = 1;
}
