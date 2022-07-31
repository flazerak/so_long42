/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:38:02 by flazerak          #+#    #+#             */
/*   Updated: 2022/07/19 15:32:14 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_elements(char **map, int nb_lines)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb_lines)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C' \
			&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '\n')
				ft_printf_error("Error\n Invalid map elements\n");
			j++;
		}
		i++;
	}
}

void	check_player(char **map, int nb_lines)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (i < nb_lines)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		ft_printf_error("Error\nThe map must have one player\n");
}

int	check_collectible(char **map, int nb_lines)
{
	int	i;
	int	j;
	int	col;

	i = 0;
	col = 0;
	while (i < nb_lines)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'C')
				col++;
			j++;
		}
		i++;
	}
	if (col == 0)
		ft_printf_error("Error\n Collectable doesn't exist\n");
	return (col);
}

void	check_exit(char **map, int nb_lines)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (i < nb_lines)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit == 0)
		ft_printf_error ("Error\nThere is no exit");
}
