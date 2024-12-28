/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:11:19 by aoger             #+#    #+#             */
/*   Updated: 2024/12/28 14:43:24 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <sys/time.h>

int	ft_animate_wall(void *param)
{
	t_game					*game;
	static struct timeval	last_time;
	struct timeval			current_time;
	long					elapsed_time;
	int						frame_rate;

	game = (t_game *)param;
	if (!game)
		return (1);
	
	frame_rate = 500000;
	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - last_time.tv_sec) * 1000000L + \
					(current_time.tv_usec - last_time.tv_usec);
	if (elapsed_time >= frame_rate)
	{
		game->frame = (game->frame + 1) % 2;
		last_time = current_time;
		ft_render_map(game);
		ft_move_enemy(game);
	}
	return (0);
}

/*
int	ft_animate_wall(void *param)
{
	static int	tick_count;
	int			frame_rate;
	t_game		*game;

	game = (t_game *)param;
	if (!game)
		return (1);
	frame_rate = 10000;
	tick_count++;
	if (tick_count >= frame_rate)
	{
		game->frame = (game->frame + 1) % 2;
		tick_count = 0;
		ft_render_map(game);
		ft_move_enemy(game);
	}
	return (0);
}
*/
