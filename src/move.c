/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:59:35 by vnazioze          #+#    #+#             */
/*   Updated: 2022/01/15 22:59:36 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int keycode, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.y;
	col = game->map.player.x;
	if (keycode == KEY_W || keycode == KEY_UP)
		move_hero(game, --line, col);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_hero(game, line, --col);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_hero(game, ++line, col);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_hero(game, line, ++col);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		exit_click(game);
	return (0);
}

void	move_hero(t_game *game, int line, int col)
{
	int	x;
	int	y;

	x = game->map.player.x;
	y = game->map.player.y;
	if (check_move(game, line, col) == TRUE)
	{
		if (game->map.map[line][col] == 'C')
			game->map.collectible--;
		game->map.map[y][x] = '0';
		game->map.player.y = line;
		game->map.player.x = col;
		render_game(game);
	}
}

int	check_move(t_game *game, int line, int col)
{
	if (game->map.map[line][col] == 'E' &&
		game->map.collectible == 0)
	{
		printf("\033[0;32m");
		printf("\n\n|==================================================|\n");
		printf("|==================|  VICTORY!  |==================|\n");
		printf("|==================================================|\n\n");
		printf("\n\033[0m");
		exit_click(game);
	}
	if (game->map.map[line][col] != 'E' &&
		game->map.map[line][col] != '1')
	{
		game->count_move++;
		printf("\033[0;34mMoves: %02d\n\033[0m", game->count_move);
		return (TRUE);
	}
	else
		return (FALSE);
}
