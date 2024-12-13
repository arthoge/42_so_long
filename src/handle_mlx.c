/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:51:37 by aoger             #+#    #+#             */
/*   Updated: 2024/12/13 14:44:32 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_display_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, \
							x * IMG_SIZE, y * IMG_SIZE);
}

void	ft_run_game(t_game *game)
{
	mlx_hook(game->win_ptr, DestroyNotify, 0, ft_handle_close, game);
	mlx_key_hook(game->win_ptr, ft_handle_keypress, game);
	mlx_loop(game->mlx_ptr);
}

int	ft_setup_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_free_tab(game->map, game->map_height);
		return (0);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->wd_width, \
									game->wd_height, "so_long");
	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		ft_free_tab(game->map, game->map_height);
		return (0);
	}
	return (1);
}
