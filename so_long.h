/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:57:17 by vnazioze          #+#    #+#             */
/*   Updated: 2022/01/16 02:39:12 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
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

# define HERO_R		"./assets/sprites/astronaut_right.xpm"
# define FLOOR		"./assets/sprites/floor.xpm"
# define WALL		"./assets/sprites/wall.xpm"
# define COIN		"./assets/sprites/collectable.xpm"
# define EXIT		"./assets/sprites/exit.xpm"

typedef enum e_bool
{
	TRUE	=	1,
	FALSE	=	0
}				t_bool;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_img
{
	void		*img;
	int			width;
	int			height;
	t_position	posimg;
}				t_img;

typedef struct s_map
{
	int			count_column;
	int			count_line;
	int			collectible;
	int			exit;
	int			cont_player;
	char		**map;
	t_position	player;
}				t_map;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct s_game
{
	int			count_move;
	t_vars		vars;
	t_img		hero;
	t_img		floor;
	t_img		wall;
	t_img		exit;
	t_img		coins;
	t_map		map;
}				t_game;

void	init_vars(t_game *game);
void	init_game(t_game *game);

void	read_map(char *argv, t_game *game);
void	count_column(t_game *game);
void	validate_map(t_game *game);
void	count_chars(int x, int y, t_game *game);

int		render_game(t_game *game);
void	render_map(t_game *game);

int		key_press(int keycode, t_game *game);
void	move_hero(t_game *game, int line, int col);
int		check_move(t_game *game, int line, int col);

void	verify_argc(int argc);
void	verify_ext(char *map_name);
void	verify_count_chars(t_game *game);
void	verify_wall(t_game *game);
void	verify_issquare(t_game *game);

void	exit_error(char *s);
int		exit_click(t_game *game);
void	free_map(t_game *game);
void	free_images(t_game *game);

#endif
