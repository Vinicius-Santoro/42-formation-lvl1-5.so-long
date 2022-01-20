/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:59:47 by vnazioze          #+#    #+#             */
/*   Updated: 2022/01/15 22:59:48 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	verify_argc(argc);
	init_vars(&game);
	read_map(argv[1], &game);
	init_game(&game);
	mlx_hook(game.vars.win, 12, 1L << 15, render_game, &game);
	mlx_hook(game.vars.win, 3, 1L << 1, key_press, &game);
	mlx_hook(game.vars.win, 17, 0L, exit_click, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}

void	init_vars(t_game *game)
{
	game->count_move = 0;
	game->map.collectible = 0;
	game->map.exit = 0;
	game->map.cont_player = 0;
}

void	init_game(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, \
	game->map.count_column * 64, game->map.count_line * 64, "So Long");
	game->hero.img = mlx_xpm_file_to_image(game->vars.mlx, HERO_R, \
	&game->hero.width, &game->hero.height);
	game->floor.img = mlx_xpm_file_to_image(game->vars.mlx, FLOOR, \
	&game->floor.width, &game->floor.height);
	game->wall.img = mlx_xpm_file_to_image(game->vars.mlx, WALL, \
	&game->wall.width, &game->wall.height);
	game->coins.img = mlx_xpm_file_to_image(game->vars.mlx, COIN, \
	&game->coins.width, &game->coins.height);
	game->exit.img = mlx_xpm_file_to_image(game->vars.mlx, EXIT, \
	&game->exit.width, &game->exit.height);
}
