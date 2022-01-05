/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:41:10 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/10 16:30:14 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define HERO "./assets/sprites/knight.xpm"

# define KEY_ESC			65307
# define KEY_Q			113
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

typedef struct s_img
{
	void		*img;
	t_vector	posimg;
	int			width;
	int			height;
}				t_img;

typedef struct s_map
{
	char		*line;
	int			count_column;
	char		*temp;
	int			count_line;
	int			column;
	int			collect;
	int			exit;
	t_vector	player;
	int			end_game;
	char		**map;
	int			validate;
	int			cont_player;
	int			player_side;
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

int		exit_click(t_game *game);
int		key_press(int keycode, t_game *game);
void	move_hero(int keycode, t_game *game, int line, int col);
int		render_game(t_game *game);
int		start_game(t_game *game);
void	start_player(t_game *game);
void	render_map(t_game *game);
void	validate_map(t_game *game);
void	count_column(t_game *game);
void	verify_map(char *argv, t_game *game);
void	second_plain(t_game *game);
char	*ft_strjoin_free(char *s1, char const *s2);
void	free_vector(t_game *game);
void	free_images(t_game *game);
void	error(char *s, int n);
void	error_cep(t_game *game);
int		validate_ber(char *s, char *ext);
void	verify_arg(int argc);
void	init_vars(t_game *game);
void	print_exit(t_game *game, int x, int y);
void	load_hero(t_game *game);
void	error_wall(t_game *game);
void	error_square(t_game *game);

#endif
