/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:55:50 by aoger             #+#    #+#             */
/*   Updated: 2024/12/18 13:12:27 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_print_file_error(void)
{
	ft_printf("Error\n");
	ft_printf("Problem with map file.\n");
}

int	ft_check_map_extension(const char *filename)
{
	const char	*extension;

	if (!filename || filename[0] == '\0')
		return (ft_print_file_error(), 0);
	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
		return (ft_print_file_error(), 0);
	return (1);
}
