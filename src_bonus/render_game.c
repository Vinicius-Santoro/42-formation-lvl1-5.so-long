/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:00:28 by vnazioze          #+#    #+#             */
/*   Updated: 2022/01/15 23:00:29 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	render_game(t_game *game)
{
	char	*s;

	render_map(game);
	if (game->map.player_side == KEY_D || game->map.player_side == KEY_RIGHT)
		mlx_put_image_to_window(
			game->vars.mlx, game->vars.win, game->hero_right.img,
			game->map.player.x * 64, game->map.player.y * 64);
	if (game->map.player_side == KEY_A || game->map.player_side == KEY_LEFT)
		mlx_put_image_to_window(
			game->vars.mlx, game->vars.win, game->hero_left.img,
			game->map.player.x * 64, game->map.player.y * 64);
	if (game->map.player_side == KEY_W || game->map.player_side == KEY_UP)
		mlx_put_image_to_window(
			game->vars.mlx, game->vars.win, game->hero_up.img,
			game->map.player.x * 64, game->map.player.y * 64);
	if (game->map.player_side == KEY_S || game->map.player_side == KEY_DOWN)
		mlx_put_image_to_window(
			game->vars.mlx, game->vars.win, game->hero_down.img,
			game->map.player.x * 64, game->map.player.y * 64);
	s = ft_itoa(game->count_move);
	mlx_string_put(game->vars.mlx, game->vars.win, 5, 25, 0xFFFFFF, "MOVES:");
	mlx_string_put(game->vars.mlx, game->vars.win, 50, 25, 0xFFFFFF, s);
	free(s);
	return (0);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->wall.img, x * 64, y * 64);
			if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->floor.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
	second_plain(game);
}

void	second_plain(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->coins.img, x * 64, y * 64);
			if (game->map.map[y][x] == 'E')
				render_exit(game, x, y);
			if (game->map.map[y][x] == 'V')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->enemy.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	render_exit(t_game *game, int x, int y)
{
	if (game->map.collectible == 0)
		mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
		game->exit_open.img, x * 64, y * 64);
	else
		mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
		game->exit_close.img, x * 64, y * 64);
}
