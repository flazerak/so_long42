/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:05:37 by flazerak          #+#    #+#             */
/*   Updated: 2022/07/19 22:00:36 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define IMG_SIZE 30

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		nb_lines;
	int		nb_col;
	int		nb_moves;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*player_up;
	void	*col_img;
	void	*exit;
	void	*wall;
	void	*black;
	void	*background;
	void	*open_door;
	void	*close_door;
	void	*cerise;
	void	*heart;
	int		player_x;
	int		player_y;
	int		width;
	int		height;
	int		i;
	int		j;
	int		w;
}	t_map;

int		get_nb_lines_of_map(char *map_name);
char	**get_map(char *map_name, int nb_lines);
void	valid_walls(char **map, int nb_lines);
void	rectangular_map(char **map, int nb_lines);
int		check_map_ext(char *str);
void	ft_printf_error(char *str);
void	ft_mlx_init(char **map, int nb_lines, t_map *vars);
void	ft_mlx_xpm_file_to_image(t_map *vars);
void	ft_mlx_put_image_to_window(t_map *vars, int keycode);
void	put_player(t_map *vars, int keycode, int i, int j);
void	put_colectabls(t_map *vars, int i, int j);
void	put_exit(t_map *vars, int i, int j);
void	check_player(char **map, int nb_lines);
void	check_map_elements(char **map, int nb_lines);
int		check_collectible(char **map, int nb_lines);
void	check_player(char **map, int nb_lines);
void	check_exit(char **map, int nb_lines);
int		key_hook(int keycode, t_map *vars);
t_map	get_cordinates(t_map *vars, char point);
void	handel_moves(t_map *vars, int keycode);
void	moves_left(t_map *vars);
void	moves_right(t_map *vars);
void	moves_down(t_map *vars);
void	moves_up(t_map *vars);
int		esc_hook(t_map *vars);

#endif