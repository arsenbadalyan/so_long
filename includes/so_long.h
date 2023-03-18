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
#define CORRECT_C "10PECV"

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
#define WRONG_WAY_CONF  "wwc"
// Functions

// Initalization
t_game *init_game();
t_mlx *init_mlx();
t_map *init_map();

// Validations
void validate_map(char *file_name, t_game *game);
void check_file_extention(char *file_name, t_game *game);
char **map_check_controller(char *file_name, t_game *game, int fd);
char *read_file_content(int fd);
char **validate_file_content(char *file_content, t_game *game);
void validate_map_size(char **map, t_game *game);
int validate_walls(char **map);
int check_wall(char *map_line, int is_centre);
void fill_map_controller(char ***map, t_game *game);
int	find_characters(char ***map, t_game *game, size_t *xy, char find);
int find_game_paths(t_game *game);
void fill_flood_map(t_map *map, size_t begin_x, size_t begin_y);

// Utils
char **dup_double(char **str, size_t size);

// Error handle
void catch_exception(int errno, char *addn);
void handle_error(int exit_code, char *type);

// Free functions
char *free_single(char **addr);
char *free_double(char ***addr);
char *free_game(t_game **game);

#endif