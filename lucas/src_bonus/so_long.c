/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:34:46 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/07 21:35:08 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		verify_arg(argc);
	init_vars(&game);
	verify_map(argv[1], &game);
	start_game(&game);
	render_map(&game);
	mlx_hook(game.vars.win, 3, 1L << 1, key_press, &game);
	mlx_hook(game.vars.win, 12, 1L << 15, render_game, &game);
	mlx_hook(game.vars.win, 17, 0L, exit_click, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}
