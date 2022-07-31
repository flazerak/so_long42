/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:16:38 by flazerak          #+#    #+#             */
/*   Updated: 2022/07/19 20:35:47 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_ext(char *str)
{
	int	l;

	l = ft_strlen(str);
	if (l > 4 && str[l - 1] == 'r' && str[l - 2] == 'e' \
	&& str[l - 3] == 'b' && str[l - 4] == '.')
		return (1);
	return (0);
}

void	ft_printf_error(char *str)
{
	if (!str)
		return ;
	ft_printf("%s", str);
	exit(1);
}

void	put_exit(t_map *vars, int i, int j)
{
	if (vars->nb_col != 0)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->close_door, j * IMG_SIZE, i * IMG_SIZE);
	else
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->open_door, j * IMG_SIZE, i * IMG_SIZE);
}
