#include "so_long.h"

void validate_map(char *file_name, t_game *game)
{
	int fd;
	char *full_path;
	char **map;

	check_file_extention(file_name);
	fd = file_access(file_name);
	map = map_check_controller(file_name, fd);
	fill_map_controller(&map, game);
}

void check_file_extention(char *file_name)
{
	char	**dot_split;
	int		i;

	i = 0;
	dot_split = ft_split(file_name, '.');
	if(!dot_split)
		catch_exception(12, 0);
	if (!dot_split[0])
	{
		free_double(&dot_split);
		handle_error(1, WRONG_EXTENTION);
	}
	while(dot_split[i + 1])
		i++;
	if(ft_strcmp(dot_split[i], "ber"))
	{
		free_double(&dot_split);
		handle_error(1, WRONG_EXTENTION);
	}
	free_double(&dot_split);
}

int file_access(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if(fd == -1)
		catch_exception(2, file_name);
	return (fd);
}