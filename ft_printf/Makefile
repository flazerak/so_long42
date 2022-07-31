# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 14:15:53 by flazerak          #+#    #+#              #
#    Updated: 2022/07/18 14:15:54 by flazerak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

LIB = ft_printf.h

SRC =	ft_printf.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putnbr.c \
	   ft_putnbr_unsigned.c \
	   ft_hexa.c \
	   ft_point.c
CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c $(LIB)
	gcc -c $(CFLAGS) $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
