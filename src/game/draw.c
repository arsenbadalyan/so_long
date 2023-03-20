#include "so_long.h"

int draw_map(t_game *game)
{
	void *sprite;
	char **map;
	int i;

	if(game->status->is_lose)
		draw_lose(game, 0, 0);
	i = 0;
	map = game->map->map;
	mlx_clear_window(game->mlx->mlx, game->mlx->win);
	if(game->status->loop++ == GAME_SPEED)
		game->status->loop = 0;
	while (map[i])
	{
		sprite_manipulation(game, map, i);
		i++;
	}
	return (0);
}

void draw_lose(t_game *game, int w, int h)
{
	if (game->status->loop_lose == 100)
		exit_game(game);
	game->status->loop_lose += 1;
}

void sprite_manipulation(t_game *game, char **map, int i)
{
	int j;
	void *sprite;

	j = 0;
	while (map[i][j])
	{
		sprite = draw_sprite(game, map[i][j], 0, 0);
		if (sprite)
		{
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
				sprite, j * WIDTH, i * HEIGHT);
			if (game->sprites[(i * game->map->x_size) + j])
				mlx_destroy_image(game->mlx->mlx,
					game->sprites[i * game->map->x_size + j]);
			game->sprites[(i * game->map->x_size) + j] = sprite;
		}
		j++;
	}
}

void *draw_sprite(t_game *game, char segment, int w, int h)
{
	char *path;
	void *sprite;

	if (segment == WALL_FLAG)
		path = ft_strjoin(WALL_PATH, "0.xpm");
	else if (segment == PLAYER_FLAG)
		path = draw_addn(game, PLAYER_PATH, MAX_ANIM_PLAYER, &game->status->p);
	else if (segment == ENEMY_FLAG)
		path = draw_addn(game, ENEMY_PATH, MAX_ANIM_ENEMY, &game->status->e);
	else if (segment == COIN_FLAG)
		path = ft_strjoin(COIN_PATH, "0.xpm");
	else if (segment == EXIT_FLAG && game->status->clc_coins != game->map->coin)
		path = ft_strjoin(EXIT_PATH, "0.xpm");
	else if (segment == EXIT_FLAG)
		path = ft_strjoin(EXIT_PATH, "1.xpm");
	else if (segment == LOSE_FLAG)
		path = ft_strdup(LOSE_PATH);
	else path = NULL;
	if(!path)
		return (NULL);
	sprite = mlx_xpm_file_to_image(game->mlx->mlx, path, &w, &h);
	free_single(&path);
	return (sprite);
}

char *draw_addn(t_game *game, char *fpath, int max_anim, size_t *status)
{
	char *integer;
	char *ext;
	char *path;

	if (!ft_strcmp(fpath, ENEMY_PATH) && game->status->loop == GAME_SPEED)
		*status += 1;
	else if (game->status->loop == GAME_SPEED)
		*status += 1;
	if (*status >= max_anim)
		*status = 0;
	integer = ft_itoa(*status);
	ext = ft_strjoin(integer, ".xpm");
	path = ft_strjoin(fpath, ext);
	free_single(&integer);
	free_single(&ext);
	return (path);
}