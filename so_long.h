/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:46:49 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/05 20:01:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

# define HERO_R		"./assets/sprites/knight_right.xpm"
# define FLOOR		"./assets/sprites/floor.xpm"
# define WALL		"./assets/sprites/wall.xpm"
# define COIN		"./assets/sprites/coins.xpm"
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
	int			column;
	int			collectible;
	int			exit;
	int			end_game;
	char		**map;
	int			validate;
	int			cont_player;
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

void	verify_map(char *argv, t_game *game)
void	verify_map_lengh_column(t_game *game)
void	verify_map_chars(t_game *game)
void	count_chars(int x, int y, t_game *game);

int		render_game(t_game *game);
void	render_map(t_game *game);
void	start_player(t_game *game);
void	second_plain(t_game *game);

int		key_press(int keycode, t_game *game);
void	move_hero(int keycode, t_game *game, int line, int col);
int		check_move(int keycode, t_game *game, int line, int col);

void	verify_argc(int argc);
void	verify_ext(char *map_name);
void	verify_count_chars(t_game *game);
void	verify_wall(t_game *game);
void	verify_is_square(t_game *game)

void	exit_error(char *s);
int		exit_click(t_game *game);
void	free_map(t_game *game);
void	free_images(t_game *game);

#endif
