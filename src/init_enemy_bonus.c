/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:00:22 by aoger             #+#    #+#             */
/*   Updated: 2024/12/17 18:37:39 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_enemies(t_game *game)
{
	int	enemy;
	int	y;
	int	x;

	game->enemies = malloc(sizeof(t_enemy) * game->nbr_enemies);
	if (!game->enemies)
		return (ft_printf("Memory allocation for enemies failed!\n"), 0);
	enemy = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'X')
			{
				game->enemies[enemy].x = x;
				game->enemies[enemy].y = y;
				enemy++;
			}
			x++;
		}
		y++;
	}
	return (1);
}
