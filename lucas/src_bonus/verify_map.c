/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:39:15 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/10 16:30:31 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	validate_ber(char *s, char *ext)
{
	int	len_s;
	int	len_ext;

	len_s = ft_strlen(s);
	len_ext = ft_strlen(ext);
	while (len_ext > 0)
	{
		if (ext[len_ext] == s[len_s])
		{
			len_ext--;
			len_s --;
		}
		else
			return (0);
	}
	return (1);
}

void	validate_cep(int x, int y, t_game *game)
{
	if (game->map.map[y][x] == 'E')
		game->map.exit++;
	if (game->map.map[y][x] == 'C')
		game->map.collect++;
	if (game->map.map[y][x] == 'P')
	{
		game->map.cont_player++;
		game->map.player.y = y;
		game->map.player.x = x;
	}
}

void	validate_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (!(ft_strchr("01CEPV", game->map.map[y][x])))
			{
				free_vector(game);
				error("Invalid char", EXIT_FAILURE);
			}
			validate_cep(x, y, game);
			x++;
		}
		y++;
	}
	error_cep(game);
	error_wall(game);
	error_square(game);
}

void	count_column(t_game *game)
{
	int	len_line;
	int	temp;
	int	i;

	game->map.count_column = 0;
	if (!game->map.temp)
		return ;
	game->map.map = ft_split(game->map.temp, '\n');
	temp = 0;
	len_line = ft_strlen(game->map.map[0]);
	i = 0;
	while (game->map.map[i] != 0)
	{
		temp = ft_strlen(game->map.map[i]);
		if (len_line != temp)
		{
			free(game->map.temp);
			free_vector(game);
			error("Invalid column size", EXIT_FAILURE);
		}
		i++;
	}
	game->map.count_column = temp;
	free(game->map.temp);
}

void	verify_map(char *argv, t_game *game)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error("file was not opened", EXIT_FAILURE);
	if (validate_ber(argv, ".ber") == 0)
		error("map is not .ber", EXIT_FAILURE);
	game->map.temp = ft_strdup("");
	game->map.count_line = 0;
	while (1)
	{
		game->map.line = get_next_line(fd);
		if (game->map.line == NULL)
			break ;
		game->map.temp = ft_strjoin_free(game->map.temp, game->map.line);
		free(game->map.line);
		game->map.count_line++;
	}
	count_column(game);
	validate_map(game);
	close(fd);
}
