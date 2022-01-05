/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:14:21 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/05 22:50:12 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int keycode, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.y;
	col = game->map.player.x;
	if (keycode == KEY_A)
		col --;
	else if (keycode == KEY_D)
		col ++;
	else if (keycode == KEY_W)
		line --;
	else if (keycode == KEY_S)
		line ++;
	else if (keycode == KEY_ESC)
		exit_click(game);
	if (game->map.end_game != 1)
		move_hero(keycode, game, line, col);
	return (0);
}

void	move_hero(int keycode, t_game *game, int line, int col)
{
	int	x;
	int	y;
	int	valid_move;

	x = game->map.player.x;
	y = game->map.player.y;
	valid_move = check_move(keycode, game, line, col);
	if (valid_move > 0)
	{
		if (game->map.map[line][col] == 'C')
			game->map.collectible--;
		game->map.map[y][x] = '0';
		game->map.player.y = line;
		game->map.player.x = col;
	}
	render_game(game);
}

int	check_move(int keycode, t_game *game, int line, int col)
{
	if (game->map.map[line][col] == '1')
		return (-1);
	if (game->map.map[line][col] == 'E' && game->map.collectible == 0)
	{
		printf("\033[0;32mVICTORY\n\033[0m");
		free_map(game);
		free_images(game);
		exit(EXIT_SUCCESS);
	}
	if (game->map.map[line][col] == 'E')
		return (-1);
	if (game->map.end_game)
		return (0);
	if (keycode == KEY_W || keycode == KEY_S || \
		keycode == KEY_A || keycode == KEY_D)
	{
		game->count_move++;
		printf("moves: %d\n", game->count_move);
		return (1);
	}
	if (keycode != KEY_W && keycode != KEY_S && \
		keycode != KEY_A && keycode != KEY_D)
		return (-1);
	else
		return (0);
}
