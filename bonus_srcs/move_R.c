/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_R.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:32:17 by flazerak          #+#    #+#             */
/*   Updated: 2022/07/20 21:44:06 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "bonus_so_long.h"

void	move_enn_right(t_map *vars, char enn)
{
	int		j;
	int		i;

	i = get_enn_i(vars, enn);
	j = get_enn_j(vars, enn);
	if (vars->map[i][j + 1] == 'P')
	{
		ft_printf ("game over!!!\n");
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(-1);
	}
	if (vars->map[i][j + 1] == '0')
	{
		vars->map[i][j] = '0';
		vars->map[i][j + 1] = enn;
	}
	if (vars->map[i][j + 1] == 'C')
	{
		vars->map[i][j] = 'C';
		vars->map[i][j + 1] = enn;
	}
}

int	get_enn_i(t_map *vars, char enn)
{
	int	k;

	if (enn == 'R')
		k = vars->r_i;
	if (enn == 'G')
		k = vars->g_i;
	return (k);
}

int	get_enn_j(t_map *vars, char enn)
{
	int	k;

	if (enn == 'R')
		k = vars->r_j;
	if (enn == 'G')
		k = vars->g_j;
	return (k);
}

void	move_enn_up(t_map *vars, char enn)
{
	int		j;
	int		i;

	i = get_enn_i(vars, enn);
	j = get_enn_j(vars, enn);
	if (vars->map[i - 1][j] == 'P')
	{
		ft_printf ("game over!!!\n");
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(-1);
	}
	if (vars->map[i - 1][j] == '0')
	{
		vars->map[i][j] = '0';
		vars->map[i - 1][j] = enn;
	}
	if (vars->map[i - 1][j] == 'C')
	{
		vars->map[i][j] = 'C';
		vars->map[i - 1][j] = enn;
	}
}

void	move_enn_down(t_map *vars, char enn)
{
	int		j;
	int		i;

	i = get_enn_i(vars, enn);
	j = get_enn_j(vars, enn);
	if (vars->map[i + 1][j] == 'P')
	{
		ft_printf ("game over!!!\n");
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(-1);
	}
	if (vars->map[i + 1][j] == '0')
	{
		vars->map[i][j] = '0';
		vars->map[i + 1][j] = enn;
	}
	if (vars->map[i + 1][j] == 'C')
	{
		vars->map[i][j] = 'C';
		vars->map[i + 1][j] = enn;
	}
}
