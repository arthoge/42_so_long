/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:12:51 by aoger             #+#    #+#             */
/*   Updated: 2024/12/17 18:47:23 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_print_nbr_move(t_game *game)
{
	game->nbr_move += 1;
	ft_printf("Moves: %d\n", game->nbr_move);
}

static void	ft_move_exit(t_game *game, int new_y, int new_x)
{
	if (game->nbr_coll == 0)
	{
		game->map[game->hero_y][game->hero_x] = '0';
		game->hero_x = new_x;
		game->hero_y = new_y;
		game->map[game->hero_y][game->hero_x] = 'P';
		ft_print_nbr_move(game);
		ft_printf("Bravo! You won the game!\n");
		ft_handle_close(game);
	}
}

static void	ft_move_empty_or_coll(t_game *game, int new_y, int new_x)
{
	if (game->map[new_y][new_x] == 'C' && game->nbr_coll > 0)
				game->nbr_coll -= 1;
	game->map[game->hero_y][game->hero_x] = '0';
	game->hero_x = new_x;
	game->hero_y = new_y;
	game->map[game->hero_y][game->hero_x] = 'P';
	ft_print_nbr_move(game);
}

void	ft_move_hero(t_game *game, int move_x, int move_y)
{
	int	new_x;
	int	new_y;

	new_x = game->hero_x + move_x;
	new_y = game->hero_y + move_y;
	if (new_x >= 0 && new_x < game->map_width && \
	new_y >= 0 && new_y < game->map_height)
	{
		if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'C')
			ft_move_empty_or_coll(game, new_y, new_x);
		else if (game->map[new_y][new_x] == 'E')
			ft_move_exit(game, new_y, new_x);
	}
	if (game->nbr_move == 1000)
	{
		ft_printf("Maximum number of moves reached, lost due to fatigue.\n");
		ft_handle_close(game);
	}
}
