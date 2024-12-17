/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:11:19 by aoger             #+#    #+#             */
/*   Updated: 2024/12/17 16:25:46 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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