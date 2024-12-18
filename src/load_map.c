/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:13:04 by aoger             #+#    #+#             */
/*   Updated: 2024/12/18 12:36:48 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**ft_append_line_to_map(char **map, char *line, int rows)
{
	char	**new_map;

	new_map = ft_realloc(map, sizeof(char *) * rows, \
	sizeof(char *) * (rows + 1));
	if (!new_map)
	{
		free(line);
		ft_free_tab(map, rows);
		return (NULL);
	}
	new_map[rows] = line;
	return (new_map);
}

static void	ft_clean_on_error(int fd, char **map, int rows)
{
	close(fd);
	ft_free_tab(map, rows);
}

char	**ft_load_map(char *file_path)
{
	int		fd;
	char	*line;
	int		rows;
	char	**map;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (NULL);
	}
	map = NULL;
	rows = 0;
	while (1)
	{
		line = get_next_line(fd);
		map = ft_append_line_to_map(map, line, rows);
		if (!map)
			return (ft_clean_on_error(fd, map, rows), NULL);
		if (!line)
			break ;
		rows++;
	}
	return (close(fd), map);
}
