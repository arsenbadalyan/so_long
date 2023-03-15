#include "so_long.h"

void map_check_controller(int fd)
{
    char *line = get_next_line(fd);
    printf("%s", line);
}

// void fill_map(int fd)
// {
//     char **map;
//     char *line;
//     int i;

//     i = 0;
//     while(1)
//     {
//         line = get_next_line(fd);
//     }
// }