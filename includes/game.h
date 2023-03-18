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
    char    **map;
    size_t  x;
    size_t  y;
    size_t  x_size;
    size_t  y_size;
    size_t  player[2];
    size_t  coin;
    size_t  enemy;
    size_t  exit;
} t_map;

#endif