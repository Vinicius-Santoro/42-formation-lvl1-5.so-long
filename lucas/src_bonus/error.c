/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:25:49 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/10 16:29:50 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	error(char *s, int n)
{
	printf("ERROR: %s\n", s);
	exit(n);
}

void	error_cep(t_game *game)
{
	if (game->map.cont_player != 1)
	{
		free_vector(game);
		error("Invalid player quantity", EXIT_FAILURE);
	}
	if (game->map.exit < 1)
	{
		free_vector(game);
		error("There are no exit", EXIT_FAILURE);
	}
	if (game->map.collect < 1)
	{
		free_vector(game);
		error("There are no collect", EXIT_FAILURE);
	}
}

void	verify_arg(int argc)
{
	if (argc > 2)
		error("Too many arguments", EXIT_FAILURE);
	if (argc < 2)
		error("Have few arguments", EXIT_FAILURE);
}

void	error_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[0][x] != '1' || \
			game->map.map[game->map.count_line - 1][x] != '1')
			{
				free_vector(game);
				error("Missing Wall", EXIT_FAILURE);
			}
			if (game->map.map[y][0] != '1' || \
			game->map.map[y][game->map.count_column - 1] != '1')
			{
				free_vector(game);
				error("Missing Wall", EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}

void	error_square(t_game *game)
{
	if (game->map.count_column == game->map.count_line)
	{
		free_vector(game);
		error("square map", EXIT_FAILURE);
	}
}
