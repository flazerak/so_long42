/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:32:17 by flazerak          #+#    #+#             */
/*   Updated: 2022/07/20 21:44:06 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "bonus_so_long.h"

void	move_enn_left(t_map *vars, char enn)
{
	int		j;
	int		i;

	i = get_enn_i(vars, enn);
	j = get_enn_j(vars, enn);
	if (vars->map[i][j - 1] == 'P')
	{
		ft_printf ("game over!!!\n");
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(-1);
	}
	if (vars->map[i][j - 1] == '0')
	{
		vars->map[i][j] = '0';
		vars->map[i][j - 1] = enn;
	}
	if (vars->map[i][j - 1] == 'C')
	{
		vars->map[i][j] = 'C';
		vars->map[i][j - 1] = enn;
	}
}

void	move_enn(t_map *vars, char enn)
{
	int	x;

	x = rand() % 4;
	if (x == 0)
		move_enn_right(vars, enn);
	if (x == 1)
		move_enn_left(vars, enn);
	if (x == 2)
		move_enn_up(vars, enn);
	if (x == 3)
		move_enn_down(vars, enn);
}
