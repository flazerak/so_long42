/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:58:39 by flazerak          #+#    #+#             */
/*   Updated: 2022/07/20 13:41:34 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_init(char **map, int nb_lines, t_map *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit (1);
	vars->mlx_win = mlx_new_window(vars->mlx, \
	(ft_strlen(map[0]) - 1) * IMG_SIZE, nb_lines * IMG_SIZE, "so_long");
	if (!vars->mlx_win)
		exit(1);
}

void	ft_mlx_xpm_file_to_image(t_map *vars)
{
	vars->height = IMG_SIZE;
	vars->width = IMG_SIZE;
	vars->wall = mlx_xpm_file_to_image(vars->mlx, \
	"./xpms/wall.xpm", &vars->width, &vars->height);
	vars->black = mlx_xpm_file_to_image(vars->mlx, \
	"./xpms/black.xpm", &vars->width, &vars->height);
	vars->open_door = mlx_xpm_file_to_image(vars->mlx, \
	"./xpms/open_door.xpm", &vars->width, &vars->height);
	vars->player_down = mlx_xpm_file_to_image(vars->mlx, \
	"./xpms/down.xpm", &vars->width, &vars->height);
	vars->col_img = mlx_xpm_file_to_image(vars->mlx, \
	"./xpms/col.xpm", &vars->width, &vars->height);
	vars->player_left = mlx_xpm_file_to_image(vars->mlx, \
	"./xpms/left.xpm", &vars->width, &vars->height);
	vars->player_right = mlx_xpm_file_to_image(vars->mlx, \
	"./xpms/right.xpm", &vars->width, &vars->height);
	vars->player_up = mlx_xpm_file_to_image(vars->mlx, \
	"./xpms/up.xpm", &vars->width, &vars->height);
	vars->close_door = mlx_xpm_file_to_image(vars->mlx, \
	"./xpms/close_door.xpm", &vars->width, &vars->height);
	vars->heart = mlx_xpm_file_to_image(vars->mlx, \
	"./xpms/heart.xpm", &vars->width, &vars->height);
	vars->cerise = mlx_xpm_file_to_image(vars->mlx, \
	"./xpms/cerise.xpm", &vars->width, &vars->height);
}

void	ft_mlx_put_image_to_window(t_map *vars, int keycode)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->nb_lines)
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, \
				vars->mlx_win, vars->wall, j * IMG_SIZE, i * IMG_SIZE);
			if (vars->map[i][j] == 'P')
				put_player(vars, keycode, i, j);
			if (vars->map[i][j] == 'C')
				put_colectabls(vars, i, j);
			if (vars->map[i][j] == 'E')
				put_exit(vars, i, j);
			if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, \
				vars->mlx_win, vars->black, j * IMG_SIZE, i * IMG_SIZE);
		}
	}
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
