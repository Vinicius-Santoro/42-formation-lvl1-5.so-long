/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:26:02 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/07 21:26:31 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	exit_click(t_game *game)
{
	printf("move %d\n", game->count_move);
	free_vector(game);
	free_images(game);
	exit(1);
}
