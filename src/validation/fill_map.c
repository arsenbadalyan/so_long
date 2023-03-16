#include "so_long.h"

void fill_map_controller(char ***map, t_game *game)
{
	size_t empty[2];

	empty[0] = 0;
	empty[1] = 0;
	if(find_characters(map, game, empty, PLAYER_FLAG) != 1 || find_characters(map, game, empty, EXIT_FLAG) != 1)
	{
		free_double(map);
		handle_error(1, WRONG_PE_CONF);
	}
	game->map->conis = find_characters(map, game, empty, COIN_FLAG);
	game->map->conis = find_characters(map, game, empty, ENEMY_FLAG);
}

int	find_characters(char ***map, t_game *game, size_t *xy, char find)
{
	size_t	counter;

	counter = 0;
	while ((*map)[xy[1]])
	{
		xy[0] = 0;
		while ((*map)[xy[1]][xy[0]])
		{
			if (!ft_strchr(CORRECT_C, (*map)[xy[1]][xy[0]]))
				return (-1);
			if ((*map)[xy[1]][xy[0]] == find && counter++ && find == PLAYER_FLAG)
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
