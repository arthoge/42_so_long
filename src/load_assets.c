/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:11:07 by aoger             #+#    #+#             */
/*   Updated: 2024/12/17 15:33:47 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_load_img(t_game *game, void **img, char *file_path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(game->mlx_ptr, file_path, &width, &height);
	if (!(*img))
		return (0);
	return (1);
}

int	ft_load_assets(t_game *game)
{
	if (!ft_load_img(game, &game->bg_img, "img/bg.xpm"))
		return (0);
	if (!ft_load_img(game, &game->wall_img, "img/wall.xpm"))
		return (0);
	if (!ft_load_img(game, &game->wall2_img, "img/wall_2.xpm"))
		return (0);
	if (!ft_load_img(game, &game->hero_img, "img/hero.xpm"))
		return (0);
	if (!ft_load_img(game, &game->coll_img, "img/coll.xpm"))
		return (0);
	if (!ft_load_img(game, &game->exit_close_img, "img/exit_close.xpm"))
		return (0);
	if (!ft_load_img(game, &game->exit_open_img, "img/exit_open.xpm"))
		return (0);
	if (!ft_load_img(game, &game->hero_rev_img, "img/hero_rev.xpm"))
		return (0);
	if (!ft_load_img(game, &game->enemy_img, "img/enemy.xpm"))
		return (0);
	return (1);
}
