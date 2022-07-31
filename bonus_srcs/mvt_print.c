/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:18:06 by flazerak          #+#    #+#             */
/*   Updated: 2022/07/20 13:42:13 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "bonus_so_long.h"

void	mvt_print(t_map *vars)
{
	vars->nb_moves_char = ft_itoa(vars->nb_moves);
	vars->nb_moves_print = ft_join("Number of movements :", \
	vars->nb_moves_char);
	mlx_string_put(vars->mlx, vars->mlx_win, 20, 20, 0x000000, \
	vars->nb_moves_print);
	free(vars->nb_moves_char);
	free(vars->nb_moves_print);
}

void	put_player(t_map	*vars, int keycode, int i, int j)
{
	if (keycode == 0 || keycode == 123)
		mlx_put_image_to_window(vars->mlx, \
		vars->mlx_win, vars->player_left, j * IMG_SIZE, i * IMG_SIZE);
	if (keycode == 2 || keycode == 124)
		mlx_put_image_to_window(vars->mlx, \
		vars->mlx_win, vars->player_right, j * IMG_SIZE, i * IMG_SIZE);
	if (keycode == 1 || keycode == 125)
		mlx_put_image_to_window(vars->mlx, \
		vars->mlx_win, vars->player_down, j * IMG_SIZE, i * IMG_SIZE);
	if (keycode == 13 || keycode == 126)
		mlx_put_image_to_window(vars->mlx, \
		vars->mlx_win, vars->player_up, j * IMG_SIZE, i * IMG_SIZE);
}

void	put_colectabls(t_map *vars, int i, int j)
{
	int	k;

	k = i * j;
	if ((k % 18 == 8) || (k % 18 == 7))
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->cerise, j * IMG_SIZE, i * IMG_SIZE);
	else if (k % 18 == 3)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->heart, j * IMG_SIZE, i * IMG_SIZE);
	else
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->col_img, j * IMG_SIZE, i * IMG_SIZE);
}
