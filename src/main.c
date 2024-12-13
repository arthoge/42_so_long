/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:30:24 by aoger             #+#    #+#             */
/*   Updated: 2024/12/12 17:46:24 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (1);
	if (!ft_init_game(av[1], &game))
		return (1);
	if (!ft_setup_mlx(&game))
		return (1);
	if (!ft_load_assets(&game))
		ft_handle_close(&game);
	ft_render_map(&game);
	ft_run_game(&game);
	return (0);
}
