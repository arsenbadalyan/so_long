#include "so_long.h"

char	**map_check_controller(t_game *game, int fd)
{
	char	*file_content;
	char	**map;

	file_content = read_file_content(fd);
	close(fd);
	if (!file_content)
		return (NULL);
	map = validate_file_content(file_content, game);
	free_single(&file_content);
	validate_map_size(map, game);
	if (validate_walls(map))
	{
		free_double(&map);
		free_game(&game);
		handle_error(1, WRONG_WALL_CONF);
	}
	return (map);
}

char	*read_file_content(int fd)
{
	char	*line;
	char	*full;
	char	*temp;

	full = ft_strdup("");
	if (!full)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || (!line[0] && !free_single(&line)))
			break ;
		temp = full;
		full = ft_strjoin(full, line);
		if (!free_single(&line) && !free_single(&temp) && !full)
			return (NULL);
	}
	temp = full;
	full = ft_strtrim(full, "\n");
	if (!free_single(&temp) && !full)
		return (NULL);
	if (!ft_strlen(full) && !free_single(&full))
		return (NULL);
	return (full);
}

char	**validate_file_content(char *file_content, t_game *game)
{
	size_t	i;
	char	**map;

	i = 0;
	while (file_content[i])
	{
		if (file_content[i] == '\n' && file_content[i + 1] == '\n')
		{
			i = 0;
			break ;
		}
		i++;
	}
	map = ft_split(file_content, '\n');
	if (!i || !map || !map[0] || !map[1] || !map[2])
	{
		free_game(&game);
		free_single(&file_content);
		if (!map)
			catch_exception(12, 0);
		free_double(&map);
		handle_error(1, WRONG_MAP_CONF);
	}
	return (map);
}

void	validate_map_size(char **map, t_game *game)
{
	size_t	size;
	size_t	first_line_size;

	size = 0;
	while (map[size])
	{
		if (size == 0)
			first_line_size = ft_strlen(map[size]);
		if (first_line_size < 3 || ft_strlen(map[size]) != first_line_size)
		{
			free_double(&map);
			free_game(&game);
			handle_error(1, WRONG_MAP_CONF);
		}
		size++;
	}
	game->map->x_size = first_line_size;
	game->map->y_size = size;
}
