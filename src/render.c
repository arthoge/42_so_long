/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:12:00 by aoger             #+#    #+#             */
/*   Updated: 2024/12/13 19:49:49 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_select_image(t_game *game, char tile, int x, int y)
{
	if (tile == '0')
		ft_display_image(game, game->bg_img, x, y);
	if (tile == '1')
		ft_display_image(game, game->wall_img, x, y);
	else if (tile == 'C')
		ft_display_image(game, game->coll_img, x, y);
	else if (tile == 'P')
	{
		if (game->hero_direction == 1)
			ft_display_image(game, game->hero_img, x, y);
		else
			ft_display_image(game, game->hero_rev_img, x, y);
	}
	else if (tile == 'E')
	{
		if (game->nbr_coll == 0)
			ft_display_image(game, game->exit_open_img, x, y);
		else
			ft_display_image(game, game->exit_close_img, x, y);
	}
}

static void	ft_draw_elements(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			tile = game->map[y][x];
			ft_select_image(game, tile, x, y);
			x++;
		}
		y++;
	}
}

void	ft_render_map(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	ft_draw_elements(game);
}

// static void	ft_draw_background(t_game *game, int wd_width, int wd_height)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < wd_height)
// 	{
// 		x = 0;
// 		while (x < wd_width)
// 		{
// 			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 									game->bg_img, x, y);
// 			x += IMG_SIZE;
// 		}
// 		y += IMG_SIZE;
// 	}
// }
