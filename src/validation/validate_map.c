#include "so_long.h"

void validate_map(char *file_name)
{
	char *line;

	check_file_extention(file_name);
	check_file_access(file_name);
}

void check_file_extention(char *file_name)
{
	int		i;
	char	**dot_split;

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

void check_file_access(char *file_name)
{
	int fd;
	char *full_path;

	full_path = ft_strjoin("./maps/", file_name);
	if (!full_path)
		catch_exception(12, 0);
	fd = open(full_path, O_RDONLY);
	free_single(&full_path);
	close(fd);
	if(fd == -1)
		catch_exception(2, file_name);
}
