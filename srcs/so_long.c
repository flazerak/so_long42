/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:58:52 by flazerak          #+#    #+#             */
/*   Updated: 2022/07/20 17:32:42 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*vars;

	vars = malloc(sizeof(t_map));
	if (argc != 2)
		ft_printf_error("Error\nInvalid number of arguments");
	if (check_map_ext(argv[1]) == 0)
		ft_printf_error("Error\nThe map filename is invalid");
	vars->nb_lines = get_nb_lines_of_map(argv[1]);
	vars->map = get_map(argv[1], vars->nb_lines);
	valid_walls(vars->map, vars->nb_lines);
	rectangular_map(vars->map, vars->nb_lines);
	check_map_elements(vars->map, vars->nb_lines);
	check_player(vars->map, vars->nb_lines);
	vars->nb_col = check_collectible(vars->map, vars->nb_lines);
	check_exit(vars->map, vars->nb_lines);
	ft_mlx_init(vars->map, vars->nb_lines, vars);
	ft_mlx_xpm_file_to_image(vars);
	ft_mlx_put_image_to_window(vars, 2);
	vars->nb_moves = 0;
	mlx_hook(vars->mlx_win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->mlx_win, 17, 1L, esc_hook, vars);
	mlx_loop(vars->mlx);
}
