#ifndef SO_LONG_H
#define SO_LONG_H

// C Libs
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

// Custom Libraries
#include <mlx.h>
#include "game.h"
#include "libft.h"
#include "get_next_line.h"

// General Defines
#define GAME_NAME "so_long"
#define CORRECT_C "10PEC"

// Flags
#define PLAYER_FLAG 'P'
#define EXIT_FLAG   'E'
#define ENEMY_FLAG  'V'
#define WALL_FLAG   '1'
#define SPACE_FLAG  '0'
#define COIN_FLAG   'C'

// Error type defines
#define WRONG_EXTENTION "wfe"
#define WRONG_ARGUMENTS "wae"
#define WRONG_MAP_CONF  "wmc"
#define WRONG_WALL_CONF "wwc"
#define WRONG_PE_CONF   "wpe"
// Functions

// Initalization
t_game *init_game();
t_mlx *init_mlx();
t_map *init_map();

// Validations
void validate_map(char *file_name, t_game *game);
void check_file_extention(char *file_name);
int file_access(char *file_name);
char **map_check_controller(char *file_name, int fd);
size_t check_map_size(int fd, size_t size, size_t length);
void free_line_and_exit(char **line);
char **fill_map(size_t map_size, int fd);
int validate_walls(char **map);
int check_wall(char *map_line, int is_centre);
void fill_map_controller(char ***map, t_game *game);
int	find_characters(char ***map, t_game *game, size_t *xy, char find);

// Error handle
void catch_exception(int errno, char *addn);
void handle_error(int exit_code, char *type);

// Free functions
char *free_single(char **addr);
char *free_double(char ***addr);

#endif