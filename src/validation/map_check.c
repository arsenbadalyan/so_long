#include "so_long.h"

void map_check_controller(char *file_name, int fd)
{
    size_t map_size;
    char **map;

    map_size = check_map_size(fd, 0, 0);
    close(fd);
    fd = file_access(file_name);
    map = fill_map(map_size, fd);
}

char **fill_map(size_t map_size, int fd)
{
    char *line;
    char **map;
    size_t i;

    i = 0;
    map = (char **)malloc(sizeof(char *) * (map_size + 1));
    map[map_size] = NULL;
    while(i < map_size)
    {
        line = get_next_line(fd);
        if(!line)
        {
            map[i] = NULL;
            free_double(&map);
            catch_exception(12, 0);
        }
        if (line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        map[i] = ft_strdup(line);
        free_single(&line);
        i++;
    }
    return (map);
}

size_t check_map_size(int fd, size_t size, size_t length)
{
    char *line;

    while(1)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        if(line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        if (!size && ft_strlen(line) < 3)
            free_line_and_exit(&line);
        if (!size)
            length = ft_strlen(line);
        if(size && ft_strlen(line) != length)
            free_line_and_exit(&line);
        free_single(&line);
        size++;
    }
    if(size < 3)
        handle_error(1, WRONG_MAP_CONF);
    return (size);
}

void free_line_and_exit(char **line)
{
    free_single(line);
    handle_error(1, WRONG_MAP_CONF);
}