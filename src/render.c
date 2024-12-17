/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:12:00 by aoger             #+#    #+#             */
/*   Updated: 2024/12/17 15:51:49 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_select_image(t_game *game, char tile, int x, int y)
{
	if (tile == '0')
		ft_display_image(game, game->bg_img, x, y);
	else if (tile == '1' && game->frame == 0)
		ft_display_image(game, game->wall_img, x, y);
	else if (tile == '1' && game->frame == 1)
		ft_display_image(game, game->wall2_img, x, y);
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
	else if (tile == 'X')
		ft_display_image(game, game->enemy_img, x, y);
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

static void	ft_draw_black_square(t_game *game, int x, int y, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + i, y + j, 0x000000);
			j++;
		}
		i++;
	}
}

void	ft_render_map(t_game *game)
{
	char	*nbr_move;

	nbr_move = ft_itoa(game->nbr_move);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	ft_draw_elements(game);
	ft_draw_black_square(game, 5, 5, 20);
	ft_draw_black_square(game, 20, 5, 20);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 13, 20, 0xFFFFFF, nbr_move);
	free(nbr_move);
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
