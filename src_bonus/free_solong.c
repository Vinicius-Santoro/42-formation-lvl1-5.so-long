/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_solong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:26:37 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/08 19:41:13 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_vector(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.count_line)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	game->map.map = NULL;
}

void	free_images(t_game *game)
{
	mlx_clear_window(game->vars.mlx, game->vars.win);
	mlx_loop_end(game->vars.mlx);
	mlx_destroy_image(game->vars.mlx, game->wall.img);
	mlx_destroy_image(game->vars.mlx, game->floor.img);
	mlx_destroy_image(game->vars.mlx, game->exit_close.img);
	mlx_destroy_image(game->vars.mlx, game->exit_open.img);
	mlx_destroy_image(game->vars.mlx, game->coins.img);
	mlx_destroy_image(game->vars.mlx, game->hero_right.img);
	mlx_destroy_image(game->vars.mlx, game->hero_left.img);
	mlx_destroy_image(game->vars.mlx, game->hero_up.img);
	mlx_destroy_image(game->vars.mlx, game->hero_down.img);
	mlx_destroy_image(game->vars.mlx, game->enemy.img);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
}
