#include "so_long.h"

int validate_walls(char **map)
{
	size_t i;

	i = 0;
	while(map[i])
	{
		if((i == 0 || !map[i + 1]) && check_wall(map[i], 0))
			return (1);
		else if(check_wall(map[i], 1))
			return (1);
		i++;
	}
	return (0);
}

int check_wall(char *map_line, int is_centre)
{
	size_t i;

	i = 0;
	while(map_line[i])
	{
		if((i == 0 || !map_line[i + 1]) && map_line[i] != '1' && is_centre)
			return (1);
		else if(map_line[i] != '1' && !is_centre)
			return (1);
		i++;
	}
	return (0);
}
