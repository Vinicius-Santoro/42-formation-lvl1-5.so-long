/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:35:17 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/08 19:46:55 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_vars(t_game *game)
{
	game->count_move = 0;
	game->map.collect = 0;
	game->map.exit = 0;
	game->map.end_game = 0;
	game->map.cont_player = 0;
	game->map.player_side = KEY_D;
}

int	start_game(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, \
	game->map.count_column * 30, game->map.count_line * 30, "So Long");
	load_hero(game);
	game->floor.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/floor.xpm", &game->floor.width, &game->floor.height);
	game->wall.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/wall.xpm", &game->wall.width, &game->wall.height);
	game->coins.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/coins.xpm", &game->coins.width, &game->coins.height);
	game->exit_close.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/exit.xpm", &game->exit_close.width, \
	&game->exit_close.height);
	game->exit_open.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/exit_open.xpm", &game->exit_open.width, \
	&game->exit_open.height);
	game->enemy.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/slime.xpm", &game->enemy.width, &game->enemy.height);
	return (0);
}

void	start_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->hero_right.img, game->map.player.x * 30, \
				game->map.player.y * 30);
			x++;
		}
		y++;
	}
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
				game->coins.img, x * 30, y * 30);
			if (game->map.map[y][x] == 'E')
				print_exit(game, x, y);
			if (game->map.map[y][x] == 'V')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->enemy.img, x * 30, y * 30);
			x++;
		}
		y++;
	}
}

void	print_exit(t_game *game, int x, int y)
{
	if (game->map.collect == 0)
		mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
		game->exit_open.img, x * 30, y * 30);
	else
		mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
		game->exit_close.img, x * 30, y * 30);
}
