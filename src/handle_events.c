/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:12:34 by aoger             #+#    #+#             */
/*   Updated: 2024/12/13 19:49:49 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_handle_close(t_game *game)
{
	if (game->map)
		ft_free_tab(game->map, game->map_height);
	if (game->bg_img)
		mlx_destroy_image(game->mlx_ptr, game->bg_img);
	if (game->coll_img)
		mlx_destroy_image(game->mlx_ptr, game->coll_img);
	if (game->hero_img)
		mlx_destroy_image(game->mlx_ptr, game->hero_img);
	if (game->hero_rev_img)
		mlx_destroy_image(game->mlx_ptr, game->hero_rev_img);
	if (game->exit_close_img)
		mlx_destroy_image(game->mlx_ptr, game->exit_close_img);
	if (game->exit_open_img)
		mlx_destroy_image(game->mlx_ptr, game->exit_open_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx_ptr, game->wall_img);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(0);
}

int	ft_handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_handle_close(game);
	if (keycode == KEY_W)
		ft_move_hero(game, 0, -1);
	if (keycode == KEY_A)
	{
		game->hero_direction = -1;
		ft_move_hero(game, -1, 0);
	}
	if (keycode == KEY_S)
		ft_move_hero(game, 0, 1);
	if (keycode == KEY_D)
	{
		game->hero_direction = 1;
		ft_move_hero(game, 1, 0);
	}
	ft_render_map(game);
	return (0);
}
