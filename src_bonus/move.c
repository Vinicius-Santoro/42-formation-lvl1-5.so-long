/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:26:58 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/10 16:46:46 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long_bonus.h"

void	print_victory(t_game *game)
{
	printf("VICTORY\n");
	free_vector(game);
	free_images(game);
	exit(EXIT_SUCCESS);
}

void	print_gameover(t_game *game)
{
	printf("GAME OVER\n");
	free_vector(game);
	free_images(game);
	exit(EXIT_SUCCESS);
}

int	check_move(int keycode, t_game *game, int line, int col)
{
	if (game->map.map[line][col] == '1')
		return (-1);
	if (game->map.map[line][col] == 'E' && game->map.collect == 0)
		print_victory(game);
	if (game->map.map[line][col] == 'E')
		return (-1);
	if (game->map.map[line][col] == 'V')
		print_gameover(game);
	if (game->map.end_game)
		return (0);
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || \
	keycode == KEY_D)
	{
		game->count_move++;
		return (1);
	}
	else
		return (-1);
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
			game->map.collect--;
		game->map.map[y][x] = '0';
		game->map.player.y = line;
		game->map.player.x = col;
		render_game(game);
	}
}

int	key_press(int keycode, t_game *game)
{
	int	line;
	int	col;

	game->map.player_side = keycode;
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
