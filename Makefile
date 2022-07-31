# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 17:14:06 by flazerak          #+#    #+#              #
#    Updated: 2022/07/20 12:17:14 by flazerak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus
SRC = ./srcs/so_long.c\
			./srcs/check_map.c\
			./srcs/error.c\
			./srcs/ft_mlx.c\
			./srcs/map_elements.c\
			./srcs/move_right.c\
			./srcs/moves_handler.c\
			./gnl/get_next_line.c\
			./gnl/get_next_line_utils.c\
			./ft_printf/ft_printf.c\
			./ft_printf/ft_hexa.c\
			./ft_printf/ft_point.c\
			./ft_printf/ft_putchar.c\
			./ft_printf/ft_putnbr.c\
			./ft_printf/ft_putnbr_unsigned.c\
			./ft_printf/ft_putstr.c

BONUS_SRC = ./bonus_srcs/so_long.c\
			./bonus_srcs/check_map.c\
			./bonus_srcs/error.c\
			./bonus_srcs/ft_mlx.c\
			./bonus_srcs/map_elements.c\
			./bonus_srcs/move_right.c\
			./bonus_srcs/moves_handler.c\
			./bonus_srcs/move_R.c\
			./bonus_srcs/mvt_print.c\
			./bonus_srcs/utils_so.c\
			./bonus_srcs/move_enn.c\
			./gnl/get_next_line.c\
			./gnl/get_next_line_utils.c\
			./ft_printf/ft_printf.c\
			./ft_printf/ft_hexa.c\
			./ft_printf/ft_point.c\
			./ft_printf/ft_putchar.c\
			./ft_printf/ft_putnbr.c\
			./ft_printf/ft_putnbr_unsigned.c\
			./ft_printf/ft_putstr.c
CC = cc
RM = rm -rf
CFLAGS = -g -Wall -Wextra -Werror
FFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit 
#FFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)
bonus: $(BONUS_NAME)

$(NAME): $(SRC) ./srcs/so_long.h ./gnl/get_next_line.h ./ft_printf/ft_printf.h
	@$(CC) $(CFLAGS) $(FFLAGS) $(SRC) -o $(NAME)
	@echo "Compiling Successfull"

$(BONUS_NAME): $(BONUS_SRC) ./bonus_srcs/bonus_so_long.h ./gnl/get_next_line.h ./ft_printf/ft_printf.h
	@$(CC) $(CFLAGS) $(FFLAGS) $(BONUS_SRC) -o $(BONUS_NAME)
	@echo "Compiling Successfull"

clean:
	@$(RM) $(OBJS) 
	@echo "Object Files Removed Successfully"

fclean:clean
	@$(RM) all $(NAME) $(BONUS_NAME)
	@echo "Clear"

re: fclean all 