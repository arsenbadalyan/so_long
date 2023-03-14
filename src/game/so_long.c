#include "so_long.h"

int main(int argc, char **argv)
{
    validate_map();
}

// int main(int argc, char **argv)
// {
//     void *mlx;
//     void *mlx_win;
//     void *img;
//     unsigned int color;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 600, 600, GAME_NAME);
//     img = mlx_new_image(mlx, 200, 200);
//     int w = 10;
//     int h = 10;
//     void *sprite = mlx_xpm_file_to_image(mlx, "./sprites/walk-sprite/001.xpm", &w, &h);
//     mlx_put_image_to_window(mlx, mlx_win, sprite, 50, 50);
//         mlx_clear_window(mlx, mlx_win);
//         mlx_loop(mlx);
//     return (0);
// }