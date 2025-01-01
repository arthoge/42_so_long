/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:55:50 by aoger             #+#    #+#             */
/*   Updated: 2025/01/01 19:37:28 by aoger            ###   ########.fr       */
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
	int			fd;
	char		buffer[1];
	ssize_t		bytes_read;

	if (!filename || filename[0] == '\0')
		return (ft_print_file_error(), 0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_print_file_error();
		return (0);
	}
	bytes_read = read(fd, buffer, 1);
	close(fd);
	if (bytes_read < 0)
		return (ft_print_file_error(), 0);
	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
		return (ft_print_file_error(), 0);
	if (ft_strlen(extension) != 4)
		return (ft_print_file_error(), 0);
	return (1);
}
