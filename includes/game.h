#ifndef GAME_H
# define GAME_H

// General Defines
# define GAME_NAME "so_long"
# define GAME_SPEED 20
# define CORRECT_C "10PECV"
# define HAVE_ACCESS "0CE"

// Window
# define WIDTH  64
# define HEIGHT 64

// Flags
# define PLAYER_FLAG 'P'
# define EXIT_FLAG   'E'
# define ENEMY_FLAG  'V'
# define WALL_FLAG   '1'
# define SPACE_FLAG  '0'
# define COIN_FLAG   'C'
# define LOSE_FLAG   'L'

// KEY CODES
# define LEFT_KEY 0
# define BOTTOM_KEY 1
# define RIGHT_KEY 2
# define UP_KEY 13
# define LEFT_ARROW 123
# define BOTTOM_ARROW 125
# define RIGHT_ARROW 124
# define UP_ARROW 126
# define ESC_KEY 53

// FLAG_PATHS
# define PLAYER_PATH "./sprites/player/"
# define ENEMY_PATH "./sprites/enemy/"
# define EXIT_PATH "./sprites/exit/"
# define COIN_PATH "./sprites/coin/"
# define WALL_PATH "./sprites/wall/"
# define LOSE_PATH "./sprites/effect_w.xpm"

// Max Animation Sprites
# define MAX_ANIM_PLAYER 3
# define MAX_ANIM_ENEMY  2

typedef struct s_game {
	struct s_mlx	*mlx;
	struct s_map	*map;
	struct s_status	*status;
	void			**sprites;
}	t_game;

typedef struct s_status {
	size_t	clc_coins;
	size_t	p;
	size_t	e;
	size_t	loop;
	size_t	loop_lose;
	size_t	is_lose;
	size_t	move_counter;
}	t_status;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_map {
	char	**map;
	size_t	x;
	size_t	y;
	size_t	x_size;
	size_t	y_size;
	size_t	player[2];
	size_t	coin;
	size_t	enemy;
	size_t	exit;
	size_t	is_exit;
}	t_map;

#endif