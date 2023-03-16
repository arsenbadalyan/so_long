#ifndef SO_LONG_H
#define SO_LONG_H

// Custom Libraries
#include <mlx.h>
#include "game.h"
#include "libft.h"
#include "get_next_line.h"
// C Libs
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

// General Defines
#define GAME_NAME "so_long"
#define MAP_PATH  "./maps/"
// Error type defines
#define WRONG_EXTENTION "wfe"
#define WRONG_ARGUMENTS "wae"
#define WRONG_MAP_CONF  "wmc"
// Functions

// Validations
void validate_map(char *file_name);
void check_file_extention(char *file_name);
int file_access(char *file_name);
void map_check_controller(char *file_name, int fd);
size_t check_map_size(int fd, size_t size, size_t length);
void free_line_and_exit(char **line);
char **fill_map(size_t map_size, int fd);

// Error handle
void catch_exception(int errno, char *addn);
void handle_error(int exit_code, char *type);

// Free functions
char *free_single(char **addr);
char *free_double(char ***addr);

#endif