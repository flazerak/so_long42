/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:27:39 by flazerak          #+#    #+#             */
/*   Updated: 2022/01/06 19:30:51 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_hexa(unsigned int n, const char *base);
int		ft_point(unsigned long n, const char *base);
int		ft_putchar(unsigned char c);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_print_args(char c, va_list *args);

#endif
