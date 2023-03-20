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

// Error type defines
#define WRONG_EXTENTION "wfe"
#define WRONG_ARGUMENTS "wae"
#define WRONG_MAP_CONF  "wmc"
#define WRONG_WALL_CONF "wwc"
#define WRONG_PE_CONF   "wpe"
#define WRONG_WAY_CONF  "wwf"

// Functions

// Initalization
t_game *init_game();
t_mlx *init_mlx();
t_map *init_map();
t_status *init_status();

// Game
void game_controller(t_game *game);
void start_mlx(t_game *game);
int exit_game(t_game *game);

// Draw functions
int draw_map(t_game *game);
void draw_lose(t_game *game, int w, int h);
void *draw_sprite(t_game *game, char segment, int w, int h);
char *draw_addn(t_game *game, char *fpath, int max_anim, size_t *status);
void sprite_manipulation(t_game *game, char **map, int i);

// Moves
int pass_key(int key, t_game *game);
void do_move(t_game *game, char **map, int x, int y);
void player_lose(t_game *game, char **map, int x, int y);

// Validations
void validate_map(char *file_name, t_game *game);
void check_file_extention(char *file_name, t_game *game);
char **map_check_controller(char *file_name, t_game *game, int fd);
char *read_file_content(int fd);
char **validate_file_content(char *file_content, t_game *game);
void validate_map_size(char **map, t_game *game);
int validate_walls(char **map);
int check_wall(char *map_line, int is_centre);
void fill_map_controller(char **map, t_game *game);
int	find_characters(char **map, t_game *game, size_t *xy, char find);
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