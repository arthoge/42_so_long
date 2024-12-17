/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:31:19 by aoger             #+#    #+#             */
/*   Updated: 2024/12/17 18:31:29 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <time.h>

static void	ft_move_empty(t_game *game, int new_y, int new_x, int i)
{
	game->map[game->enemies[i].y][game->enemies[i].x] = '0';
	game->enemies[i].x = new_x;
	game->enemies[i].y = new_y;
	game->map[new_y][new_x] = 'X';
}

static void	ft_set_rand_direction(int *move_x, int *move_y)
{
	int	direction;

	srand(time(NULL));
	direction = rand() % 4;
	if (direction == 0)
	{
		*move_x = 0;
		*move_y = -1;
	}
	else if (direction == 1)
	{
		*move_x = -1;
		*move_y = 0;
	}
	else if (direction == 2)
	{
		*move_x = 0;
		*move_y = 1;
	}
	else
	{
		*move_x = 1;
		*move_y = 0;
	}
}

static int	ft_check_no_collision(t_game *game, int new_x, int new_y)
{
	if (new_x == game->hero_x && new_y == game->hero_y)
		return (0);
	return (1);
}

void	ft_move_enemy(t_game *game)
{
	int	move_x;
	int	move_y;
	int	new_x;
	int	new_y;
	int	i;

	i = 0;
	while (i < game->nbr_enemies)
	{
		ft_set_rand_direction(&move_x, &move_y);
		new_x = game->enemies[i].x + move_x;
		new_y = game->enemies[i].y + move_y;
		if (!ft_check_no_collision(game, new_x, new_y))
		{
			ft_printf("You get caught by the enemy!\n");
			ft_handle_close(game);
		}
		if (new_x >= 0 && new_x < game->map_width && \
		new_y >= 0 && new_y < game->map_height)
		{
			if (game->map[new_y][new_x] == '0')
				ft_move_empty(game, new_y, new_x, i);
		}
		i++;
	}
}
