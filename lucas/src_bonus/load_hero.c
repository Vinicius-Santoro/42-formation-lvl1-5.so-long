/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:37:59 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/08 19:40:46 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	load_hero(t_game *game)
{
	game->hero_right.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/knight_right.xpm", &game->hero_right.width, \
	&game->hero_right.height);
	game->hero_left.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/knight_left.xpm", &game->hero_left.width, \
	&game->hero_left.height);
	game->hero_up.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/knight_up.xpm", &game->hero_up.width, \
	&game->hero_up.height);
	game->hero_down.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/knight_down.xpm", &game->hero_down.width, \
	&game->hero_down.height);
}
