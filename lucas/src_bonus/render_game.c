/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:31:19 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/10 16:42:11 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
				game->wall.img, x * 30, y * 30);
			else
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->floor.img, x * 30, y * 30);
			x++;
		}
		y++;
	}
	if (game->count_move == 0)
	{
		start_player(game);
	}
	second_plain(game);
}

int	render_game(t_game *game)
{
	char	*s;

	render_map(game);
	if (game->map.player_side == KEY_D)
		mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
		game->hero_right.img, game->map.player.x * 30, game->map.player.y * 30);
	if (game->map.player_side == KEY_A)
		mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
		game->hero_left.img, game->map.player.x * 30, game->map.player.y * 30);
	if (game->map.player_side == KEY_W)
		mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
		game->hero_up.img, game->map.player.x * 30, game->map.player.y * 30);
	if (game->map.player_side == KEY_S)
		mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
		game->hero_down.img, game->map.player.x * 30, game->map.player.y * 30);
	s = ft_itoa(game->count_move);
	mlx_string_put(game->vars.mlx, game->vars.win, 175, 10, 0xFFFFFF, s);
	mlx_string_put(game->vars.mlx, game->vars.win, 140, 10, 0xFFFFFF, "Move: ");
	free(s);
	return (0);
}
