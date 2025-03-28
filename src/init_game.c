/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:10:12 by aoger             #+#    #+#             */
/*   Updated: 2025/01/01 19:05:28 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_init_struct(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->wd_width = 0;
	game->wd_height = 0;
	game->bg_img = NULL;
	game->coll_img = NULL;
	game->hero_img = NULL;
	game->hero_rev_img = NULL;
	game->exit_close_img = NULL;
	game->exit_open_img = NULL;
	game->wall_img = NULL;
	game->wall2_img = NULL;
	game->enemy_img = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->nbr_coll = 0;
	game->nbr_move = 0;
	game->hero_direction = 1;
	game->frame = 0;
	game->nbr_enemies = 0;
	game->enemies = NULL;
}

static int	ft_calculate_window_size(t_game *game)
{
	game->wd_width = game->map_width * IMG_SIZE;
	game->wd_height = game->map_height * IMG_SIZE;
	if (game->wd_width > 1920 || game->wd_height > 1080)
	{
		ft_printf("Error\n");
		ft_printf("Your map exceeds window maximum size\n");
		return (0);
	}
	if (game->wd_width <= 0 || game->wd_height <= 0)
	{
		ft_printf("Error\n");
		ft_printf("Invalid window: %d x %d\n", game->wd_width, game->wd_height);
		return (0);
	}
	return (1);
}

static void	ft_init_hero_coll_enemies(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->hero_x = x;
				game->hero_y = y;
			}
			if (game->map[y][x] == 'C')
				game->nbr_coll += 1;
			if (game->map[y][x] == 'X')
				game->nbr_enemies += 1;
			x++;
		}
		y++;
	}
}

static int	ft_count_rows(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

int	ft_init_game(char *file_path, t_game *game)
{
	ft_srand();
	ft_init_struct(game);
	game->map = ft_load_map(file_path);
	if (!game->map)
		return (0);
	game->map_height = ft_count_rows(game->map);
	if (!ft_check_map(game))
		return (ft_free_tab(game->map, game->map_height), 0);
	ft_init_hero_coll_enemies(game);
	if (!ft_check_valid_path(game))
		return (ft_free_tab(game->map, game->map_height), 0);
	if (!ft_init_enemies(game))
		return (ft_free_tab(game->map, game->map_height), 0);
	if (!ft_calculate_window_size(game))
		return (free(game->enemies), \
		ft_free_tab(game->map, game->map_height), 0);
	return (1);
}
