#include "so_long.h"

char	*free_single(char **addr)
{
	if (*addr)
	{
		free(*addr);
		*addr = 0;
	}
	return (0);
}

char	*free_double(char ***addr)
{
	int	i;

	i = 0;
	if (*addr)
	{
		while ((*addr)[i])
		{
			free((*addr)[i]);
			i++;
		}
		free(*addr);
	}
	return (0);
}

char	*free_game(t_game **game)
{
	t_game	*gm;

	gm = *game;
	if (!gm)
		return (0);
	free_double(&gm->map->map);
	free(gm->map);
	free(gm->mlx);
	free(gm->status);
	free(gm);
	return (0);
}
