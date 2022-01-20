/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:59:41 by vnazioze          #+#    #+#             */
/*   Updated: 2022/01/15 22:59:42 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render_game(t_game *game)
{
	render_map(game);
	mlx_put_image_to_window(
		game->vars.mlx, game->vars.win, game->hero.img,
		game->map.player.x * 64, game->map.player.y * 64);
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
			if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win,
					game->floor.img, x * 64, y * 64);
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win,
					game->wall.img, x * 64, y * 64);
			if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win,
					game->coins.img, x * 64, y * 64);
			if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win,
					game->exit.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
