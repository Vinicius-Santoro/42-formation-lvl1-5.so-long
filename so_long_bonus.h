/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:56:55 by vnazioze          #+#    #+#             */
/*   Updated: 2022/01/19 20:34:00 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define KEY_ESC	65307
# define KEY_Q		113

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

# define FLOOR		"./assets/sprites/floor.xpm"
# define WALL		"./assets/sprites/wall.xpm"
# define COIN		"./assets/sprites/collectable.xpm"
# define EXIT		"./assets/sprites/exit.xpm"
# define EXIT_OPEN	"./assets/sprites/exit_open.xpm"
# define SLIME		"./assets/sprites/alien.xpm"
# define HERO_R		"./assets/sprites/astronaut_right.xpm"
# define HERO_L		"./assets/sprites/astronaut_left.xpm"
# define HERO_U		"./assets/sprites/astronaut_up.xpm"
# define HERO_D		"./assets/sprites/astronaut_down.xpm"

typedef enum e_bool
{
	TRUE	=	1,
	FALSE	=	0
}				t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}		t_position;

typedef struct s_img
{
	void		*img;
	t_position	posimg;
	int			width;
	int			height;
}				t_img;

typedef struct s_map
{
	int			count_column;
	int			count_line;
	int			collectible;
	int			exit;
	int			cont_player;
	int			player_side;
	char		**map;
	t_position	player;
}		t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

typedef struct s_game
{
	int		count_move;
	t_vars	vars;
	t_img	hero_right;
	t_img	hero_left;
	t_img	hero_up;
	t_img	hero_down;
	t_img	floor;
	t_img	wall;
	t_img	exit_close;
	t_img	exit_open;
	t_img	coins;
	t_map	map;
	t_img	enemy;
}		t_game;

void	init_vars(t_game *game);
int		init_game(t_game *game);

void	read_map(char *argv, t_game *game);
void	validate_map(t_game *game);
void	count_column(t_game *game);
void	count_chars(int x, int y, t_game *game);

void	verify_argc(int argc);
void	verify_ext(char *map_name);
void	verify_wall(t_game *game);
void	verify_count_chars(t_game *game);
void	verify_issquare(t_game *game);

int		key_press(int keycode, t_game *game);
void	move_hero(t_game *game, int line, int col, int keycode);
int		check_move(t_game *game, int line, int col);
void	print_victory(t_game *game);
void	print_gameover(t_game *game);

int		render_game(t_game *game);
void	render_map(t_game *game);
void	render_exit(t_game *game, int x, int y);
void	second_plain(t_game *game);

void	exit_error(char *s);
int		exit_click(t_game *game);
void	free_map(t_game *game);
void	free_images(t_game *game);

#endif
