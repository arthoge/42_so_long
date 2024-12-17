/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:54:14 by aoger             #+#    #+#             */
/*   Updated: 2024/12/17 16:31:14 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**ft_create_tab_copy(char **tab, int tab_height)
{
	char	**tab_copy;
	int		row;

	tab_copy = malloc(sizeof(char *) * (tab_height + 1));
	if (!tab_copy)
		return (NULL);
	row = 0;
	while (row < tab_height)
	{
		tab_copy[row] = ft_strdup(tab[row]);
		if (!tab_copy[row])
		{
			ft_free_tab(tab_copy, row);
			return (NULL);
		}
		row++;
	}
	tab_copy[row] = NULL;
	return (tab_copy);
}

static void	ft_flood_fill(char **map, int x, int y, char target)
{
	int	row_len;

	if (x < 0 || y < 0 || !map[y])
		return ;
	row_len = (int)ft_strlen(map[y]);
	if (map[y][row_len - 1] == '\n')
		row_len -= 1;
	if (x >= row_len)
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] != '0' && map[y][x] != target && map[y][x] != 'P' && map[y][x] != 'C')
		return ;
	map[y][x] = 'V';
	ft_flood_fill(map, x + 1, y, target);
	ft_flood_fill(map, x - 1, y, target);
	ft_flood_fill(map, x, y + 1, target);
	ft_flood_fill(map, x, y - 1, target);
}

static int	ft_can_reach(t_game *game, char target)
{
	char	**map_copy;
	int		row;

	map_copy = ft_create_tab_copy(game->map, game->map_height);
	if (!map_copy)
		return (0);
	ft_flood_fill(map_copy, game->hero_x, game->hero_y, target);
	row = 0;
	while (row < game->map_height)
	{
		if (ft_strchr(map_copy[row], target))
		{
			ft_free_tab(map_copy, game->map_height);
			return (0);
		}
		row++;
	}
	ft_free_tab(map_copy, game->map_height);
	return (1);
}

int	ft_check_valid_path(t_game *game)
{
	if (!ft_can_reach(game, 'C'))
	{
		ft_printf("Error\n");
		ft_printf("No valid path, impossible to reach all collectibles.\n");
		return (0);
	}
	if (!ft_can_reach(game, 'E'))
	{
		ft_printf("Error\n");
		ft_printf("No valid path, impossible to reach exit.\n");
		return (0);
	}
	return (1);
}
