/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:00:19 by vnazioze          #+#    #+#             */
/*   Updated: 2022/01/19 20:32:37 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	key_press(int keycode, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.y;
	col = game->map.player.x;
	if (keycode == KEY_W || keycode == KEY_UP)
		move_hero(game, --line, col, keycode);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_hero(game, line, --col, keycode);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_hero(game, ++line, col, keycode);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_hero(game, line, ++col, keycode);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		exit_click(game);
	return (0);
}

void	move_hero(t_game *game, int line, int col, int keycode)
{
	int	x;
	int	y;

	game->map.player_side = keycode;
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
		print_victory(game);
	if (game->map.map[line][col] == 'V')
		print_gameover(game);
	if (game->map.map[line][col] != 'E' &&
		game->map.map[line][col] != '1')
	{
		game->count_move++;
		return (TRUE);
	}
	else
		return (FALSE);
}

void	print_victory(t_game *game)
{
	printf("\033[0;32m");
	printf("\n\n|==================================================|\n");
	printf("|==================|  VICTORY!  |==================|\n");
	printf("|==================================================|\n\n");
	printf("\n\033[0m");
	exit_click(game);
}

void	print_gameover(t_game *game)
{
	printf("\033[0;31m");
	printf("\n\n|==================================================|\n");
	printf("|==================|  GAMEOVER  |==================|\n");
	printf("|==================================================|\n\n");
	printf("\n\033[0m");
	exit_click(game);
}
