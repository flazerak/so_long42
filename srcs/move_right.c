/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:13:12 by flazerak          #+#    #+#             */
/*   Updated: 2022/07/19 17:08:48 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves_left(t_map *vars)
{
	int	j;
	int	i;

	j = vars->player_x;
	i = vars->player_y;
	if (vars->map[i][j - 1] != '1' && vars->map[i][j - 1] != 'E')
	{
		if (vars->map[i][j - 1] == 'C')
			vars->nb_col--;
		vars->map[i][j - 1] = 'P';
		vars->map[i][j] = '0';
		vars->nb_moves++;
		ft_printf("moves = %d\n", vars->nb_moves);
	}
	if (vars->map[i][j - 1] == 'E' && vars->nb_col == 0)
	{
		vars->nb_moves++;
		ft_printf("moves = %d\n", vars->nb_moves);
		ft_printf("you win!!\n");
		vars->map[i][j] = '0';
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(-1);
	}
}

void	moves_right(t_map *vars)
{
	int	x;
	int	y;

	x = vars->player_x;
	y = vars->player_y;
	if (vars->map[y][x + 1] != '1' && vars->map[y][x + 1] != 'E')
	{
		if (vars->map[y][x + 1] == 'C')
			vars->nb_col--;
		vars->map[y][x + 1] = 'P';
		vars->map[y][x] = '0';
		vars->nb_moves++;
		ft_printf("moves = %d\n", vars->nb_moves);
	}
	if (vars->map[y][x + 1] == 'E' && vars->nb_col == 0)
	{
		vars->nb_moves++;
		ft_printf("moves = %d\n", vars->nb_moves);
		vars->map[y][x] = '0';
		ft_printf("you win!!\n");
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(-1);
	}
}

void	moves_down(t_map *vars)
{
	int	x;
	int	y;

	x = vars->player_x;
	y = vars->player_y;
	if (vars->map[y + 1][x] != '1' && vars->map[y + 1][x] != 'E')
	{
		if (vars->map[y + 1][x] == 'C')
			vars->nb_col--;
		vars->map[y + 1][x] = 'P';
		vars->map[y][x] = '0';
		vars->nb_moves++;
		ft_printf("moves = %d\n", vars->nb_moves);
	}
	if (vars->map[y + 1][x] == 'E' && vars->nb_col == 0)
	{
		vars->nb_moves++;
		ft_printf("moves = %d\n", vars->nb_moves);
		ft_printf("you win!!\n");
		vars->map[y][x] = '0';
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(-1);
	}
}

void	moves_up(t_map *vars)
{
	int	x;
	int	y;

	x = vars->player_x;
	y = vars->player_y;
	if (vars->map[y - 1][x] != '1' && vars->map[y - 1][x] != 'E')
	{
		if (vars->map[y - 1][x] == 'C')
			vars->nb_col--;
		vars->map[y - 1][x] = 'P';
		vars->map[y][x] = '0';
		vars->nb_moves++;
		ft_printf("moves = %d\n", vars->nb_moves);
	}
	if (vars->map[y - 1][x] == 'E' && vars->nb_col == 0)
	{
		vars->nb_moves++;
		ft_printf("moves = %d\n", vars->nb_moves);
		ft_printf("you win!!\n");
		vars->map[y][x] = '0';
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(-1);
	}
}
