/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:00:31 by vnazioze          #+#    #+#             */
/*   Updated: 2022/01/18 00:09:02 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	verify_argc(argc);
	init_vars(&game);
	read_map(argv[1], &game);
	init_game(&game);
	mlx_hook(game.vars.win, 3, 1L << 1, key_press, &game);
	mlx_hook(game.vars.win, 12, 1L << 15, render_game, &game);
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
	game->map.player_side = KEY_D;
}

void	load_hero(t_game *game)
{
	game->hero_right.img = mlx_xpm_file_to_image(game->vars.mlx, \
	HERO_R, &game->hero_right.width, \
	&game->hero_right.height);
	game->hero_left.img = mlx_xpm_file_to_image(game->vars.mlx, \
	HERO_L, &game->hero_left.width, \
	&game->hero_left.height);
	game->hero_up.img = mlx_xpm_file_to_image(game->vars.mlx, \
	HERO_U, &game->hero_up.width, \
	&game->hero_up.height);
	game->hero_down.img = mlx_xpm_file_to_image(game->vars.mlx, \
	HERO_D, &game->hero_down.width, \
	&game->hero_down.height);
}

int	init_game(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, \
	game->map.count_column * 64, game->map.count_line * 64, "So Long");
	load_hero(game);
	game->floor.img = mlx_xpm_file_to_image(game->vars.mlx, FLOOR, \
	&game->floor.width, &game->floor.height);
	game->wall.img = mlx_xpm_file_to_image(game->vars.mlx, WALL, \
	&game->wall.width, &game->wall.height);
	game->coins.img = mlx_xpm_file_to_image(game->vars.mlx, COIN, \
	&game->coins.width, &game->coins.height);
	game->exit_close.img = mlx_xpm_file_to_image(game->vars.mlx, EXIT, \
	&game->exit_close.width, &game->exit_close.height);
	game->exit_open.img = mlx_xpm_file_to_image(game->vars.mlx, EXIT_OPEN, \
	&game->exit_open.width, &game->exit_open.height);
	game->enemy.img = mlx_xpm_file_to_image(game->vars.mlx, SLIME, \
	&game->enemy.width, &game->enemy.height);
	return (0);
}
