/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:13:12 by flazerak          #+#    #+#             */
/*   Updated: 2022/07/20 21:14:53 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	moves_left(t_map *vars)
{
	int	j;
	int	i;

	j = vars->player_x;
	i = vars->player_y;
	if (vars->map[i][j - 1] == 'R' || vars->map[i][j - 1] == 'G')
		esc_hook(vars);
	if (vars->map[i][j - 1] != '1' && vars->map[i][j - 1] != 'E')
	{
		if (vars->map[i][j - 1] == 'C')
			vars->nb_col--;
		vars->map[i][j - 1] = 'P';
		vars->map[i][j] = '0';
		vars->nb_moves++;
	}
	if (vars->map[i][j - 1] == 'E' && vars->nb_col == 0)
		you_win(vars);
}

void	moves_right(t_map *vars)
{
	int	j;
	int	i;

	j = vars->player_x;
	i = vars->player_y;
	if (vars->map[i][j + 1] == 'R' || vars->map[i][j + 1] == 'G')
		esc_hook(vars);
	if (vars->map[i][j + 1] != '1' && vars->map[i][j + 1] != 'E')
	{
		if (vars->map[i][j + 1] == 'C')
			vars->nb_col--;
		vars->map[i][j + 1] = 'P';
		vars->map[i][j] = '0';
		vars->nb_moves++;
	}
	if (vars->map[i][j + 1] == 'E' && vars->nb_col == 0)
		you_win(vars);
}

void	moves_down(t_map *vars)
{
	int	j;
	int	i;

	j = vars->player_x;
	i = vars->player_y;
	if (vars->map[i + 1][j] == 'R' || vars->map[i + 1][j] == 'G')
		esc_hook(vars);
	if (vars->map[i + 1][j] != '1' && vars->map[i + 1][j] != 'E')
	{
		if (vars->map[i + 1][j] == 'C')
			vars->nb_col--;
		vars->map[i + 1][j] = 'P';
		vars->map[i][j] = '0';
		vars->nb_moves++;
	}
	if (vars->map[i + 1][j] == 'E' && vars->nb_col == 0)
		you_win(vars);
}

void	moves_up(t_map *vars)
{
	int	j;
	int	i;

	j = vars->player_x;
	i = vars->player_y;
	if (vars->map[i - 1][j] == 'R' || vars->map[i - 1][j] == 'G')
		esc_hook(vars);
	if (vars->map[i - 1][j] != '1' && vars->map[i - 1][j] != 'E')
	{
		if (vars->map[i - 1][j] == 'C')
			vars->nb_col--;
		vars->map[i - 1][j] = 'P';
		vars->map[i][j] = '0';
		vars->nb_moves++;
	}
	if (vars->map[i - 1][j] == 'E' && vars->nb_col == 0)
		you_win(vars);
}

void	you_win(t_map	*vars)
{
	int	j;
	int	i;

	j = vars->player_x;
	i = vars->player_y;
	vars->nb_moves++;
	ft_printf("you win!!\n");
	vars->map[i][j] = '0';
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(-1);
}
