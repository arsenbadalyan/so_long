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
// Functions

// Validations
void validate_map(char *file_name);
void check_file_extention(char *file_name);
void check_file_access(char *file_name);
void map_check_controller(int fd);

// Error handle
void catch_exception(int errno, char *addn);
void handle_error(int exit_code, char *type);

// Free functions
char *free_single(char **addr);
char *free_double(char ***addr);

#endif