#ifndef GAME_H
#define GAME_H

typedef struct s_game {
    struct s_mlx *mlx;
    struct s_map *map;
} t_game;

typedef struct s_mlx {
    void *mlx;
    void *win;
} t_mlx;

typedef struct s_map {
    char **map;
} t_map;

#endif