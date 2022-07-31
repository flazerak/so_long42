/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:10:38 by flazerak          #+#    #+#             */
/*   Updated: 2022/07/20 20:13:18 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "bonus_so_long.h"

int	key_hook(int keycode, t_map *vars)
{
	t_map	p;

	p = get_cordinates(vars, 'P');
	vars->player_x = p.player_x;
	vars->player_y = p.player_y;
	p = get_cordinates(vars, 'R');
	vars->r_j = p.player_x;
	vars->r_i = p.player_y;
	p = get_cordinates(vars, 'G');
	vars->g_j = p.player_x;
	vars->g_i = p.player_y;
	handel_moves(vars, keycode);
	ft_mlx_put_image_to_window(vars, keycode);
	return (1);
}

t_map	get_cordinates(t_map *vars, char point)
{
	t_map	cordinates;
	int		i;
	int		j;

	i = -1;
	cordinates.player_x = 0;
	cordinates.player_y = 0;
	while (++i < vars->nb_lines)
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == point)
			{
				cordinates.player_x = j;
				cordinates.player_y = i;
			}
		}
	}
	return (cordinates);
}

void	handel_moves(t_map *vars, int keycode)
{
	if (keycode == 0 || keycode == 123)
		moves_left(vars);
	if (keycode == 2 || keycode == 124)
		moves_right(vars);
	if (keycode == 1 || keycode == 125)
		moves_down(vars);
	if (keycode == 13 || keycode == 126)
		moves_up(vars);
	if (keycode == 53)
	{
		ft_printf ("game over!!!\n");
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(-1);
	}
	if (keycode != 53)
	{	
		if (vars->r_i && vars->r_j)
			move_enn(vars, 'R');
		if (vars->g_i && vars->g_j)
			move_enn(vars, 'G');
	}
}

int	esc_hook(t_map *vars)
{
	ft_printf("game over!!!\n");
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free(vars->map);
	exit(0);
}
