/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:23:36 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/05 20:02:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	verify_map(char *argv, t_game *game)
{
	int		fd;
	char	*tmp_map;
	char	*tmp_line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit_error("file not opened");
	verify_ext(argv);
	tmp_map = ft_strdup("");
	game->map.count_line = 0;
	while (TRUE)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL)
			break ;
		tmp_map = ft_strjoin(tmp_map, tmp_line);
		free(tmp_line);
		game->map.count_line++;
	}
	game->map.map = ft_split(tmp_map, '\n');
	free(tmp_line);
	free(tmp_map);
	count_column(game);
	validate_map(game);
	close(fd);
}

void	verify_map_lengh_column(t_game *game)
{
	int	len_line;
	int	temp;
	int	i;

	game->map.count_column = 0;
	temp = 0;
	len_line = ft_strlen(game->map.map[0]);
	i = 0;
	while (game->map.map[i] != 0)
	{
		temp = ft_strlen(game->map.map[i]);
		if (len_line != temp)
		{
			free_map(game);
			exit_error("Invalid column size");
		}
		i++;
	}
	game->map.count_column = temp;
	free(len_line);
	free()
}

void	verify_map_chars(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (ft_strchr("01CEP", game->map.map[y][x]) == NULL)
			{
				free_map(game);
				exit_error("Invalid char");
			}
			count_chars(x, y, game);
			x++;
		}
		y++;
	}
	verify_wall(game);
	verify_count_chars(game);
	verify_issquare(game);
}

void	count_chars(int x, int y, t_game *game)
{
	if (game->map.map[y][x] == 'E')
		game->map.exit++;
	if (game->map.map[y][x] == 'C')
		game->map.collectible++;
	if (game->map.map[y][x] == 'P')
	{
		game->map.cont_player++;
		game->map.player.y = y;
		game->map.player.x = x;
	}
}
