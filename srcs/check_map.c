/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:16:47 by flazerak          #+#    #+#             */
/*   Updated: 2022/07/18 16:20:55 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_nb_lines_of_map(char *map_name)
{
	int		fd;
	char	*line;
	int		nb_lines;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_printf_error("Error\nCan't open file decriptor.\n");
	line = get_next_line(fd);
	if (!line)
		ft_printf_error("Error\nEmpty Map.\n");
	free(line);
	nb_lines = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		nb_lines++;
	}
	close(fd);
	return (nb_lines);
}

char	**get_map(char *map_name, int nb_lines)
{
	char	**map;
	int		fd;
	int		i;

	map = (char **)malloc(sizeof(char *) * (nb_lines + 1));
	if (!map)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = -1;
	while (++i < nb_lines)
		map[i] = get_next_line(fd);
	close(fd);
	return (map);
}

void	valid_walls(char **map, int nb_lines)
{
	int	i;
	int	len;

	i = 0;
	while (map[0][i] != '\n' && map[nb_lines - 1][i] != '\0')
	{
		if (map[0][i] != '1' || map[nb_lines - 1][i] != '1')
			ft_printf_error("Error\n The map is not surrounded by walls\n");
		i++;
	}
	len = ft_strlen(map[0]);
	i = 0;
	while (i < nb_lines)
	{
		if (map[i][0] != '1' || map[i][len - 2] != '1')
			ft_printf_error("Error\n The map is not surrounded by walls\n");
		i++;
	}
}

void	rectangular_map(char **map, int nb_lines)
{
	int	i;

	i = 0;
	while (i < nb_lines - 2)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]) \
		|| ft_strlen(map[nb_lines - 1]) != ft_strlen(map[nb_lines - 2]) - 1)
			ft_printf_error("Error\n The map isn't Rectangular\n");
		i++;
	}
}
