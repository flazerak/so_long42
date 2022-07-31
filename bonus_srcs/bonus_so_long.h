/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:05:37 by flazerak          #+#    #+#             */
/*   Updated: 2022/07/20 18:04:18 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_SO_LONG_H
# define BONUS_SO_LONG_H

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
	char	*nb_moves_char;
	char	*nb_moves_print;
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
	void	*red_en;
	void	*green_en;
	int		player_x;
	int		player_y;
	int		r_j;
	int		r_i;
	int		g_j;
	int		g_i;
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
void	check_enn(char **map, int nb_lines);
int		key_hook(int keycode, t_map *vars);
t_map	get_cordinates(t_map *vars, char point);
void	handel_moves(t_map *vars, int keycode);
void	moves_left(t_map *vars);
void	moves_right(t_map *vars);
void	moves_down(t_map *vars);
void	moves_up(t_map *vars);
int		esc_hook(t_map *vars);
void	move_enn(t_map *vars, char enn);
void	you_win(t_map *vars);
void	mvt_print(t_map *vars);
int		nbr_chr(long int n);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dst, const void *src, int n);
void	*ft_memmove(void *dst, const void *src, int len);
char	*ft_join(char *s1, char *s2);
void	move_enn_right(t_map *vars, char enn);
void	move_enn_up(t_map *vars, char enn);
void	move_enn_down(t_map *vars, char enn);
void	move_enn_left(t_map *vars, char enn);
int		get_enn_i(t_map *vars, char enn);
int		get_enn_j(t_map *vars, char enn);
void	ft_mlx_xpm_file_to_image_bonus(t_map *vars);
void	ft_mlx_put_image_to_window_bonus(t_map *vars, int i, int j);

#endif
