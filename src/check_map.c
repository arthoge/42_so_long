/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:01:05 by aoger             #+#    #+#             */
/*   Updated: 2024/12/14 00:30:21 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_check_rectangle(t_game *game)
{
	int	rows;
	int	row_size;

	if (!game->map[0] || !game->map[1] || !game->map[2])
		return (0);
	game->map_width = (int)ft_strlen(game->map[0]) - NEWLINE_CHAR;
	if (game->map_width < 3)
		return (0);
	rows = 1;
	while (game->map[rows])
	{
		row_size = (int)ft_strlen(game->map[rows]);
		if (row_size > 0 && game->map[rows][row_size - 1] == '\n')
			row_size -= NEWLINE_CHAR;
		if (row_size != game->map_width)
			return (0);
		rows++;
	}
	game->map_height = rows;
	return (1);
}

static int	ft_check_walls(t_game *game, char wall)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		if (game->map[0][x] != wall)
			return (0);
		if (game->map[game->map_height - 1][x] != wall)
			return (0);
		x++;
	}
	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][0] != wall)
			return (0);
		if (game->map[y][game->map_width - 1] != wall)
			return (0);
		y++;
	}
	return (1);
}

static int	ft_count_elements(t_game *game, char element)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == element)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static int	ft_check_elements(t_game *game)
{
	if (ft_count_elements(game, 'E') != 1)
		return (0);
	if (ft_count_elements(game, 'C') < 1)
		return (0);
	if (ft_count_elements(game, 'P') != 1)
		return (0);
	return (1);
}

int	ft_check_map(t_game *game)
{
	if (!ft_check_rectangle(game))
	{
		ft_printf("Error\n");
		ft_printf("Map is not a rectangle.\n");
		return (0);
	}
	if (!ft_check_elements(game))
	{
		ft_printf("Error\n");
		ft_printf("Not the right count of elements on the map.\n");
		return (0);
	}
	if (!ft_check_walls(game, '1'))
	{
		ft_printf("Error\n");
		ft_printf("Problem with walls all around the map.\n");
		return (0);
	}
	return (1);
}
