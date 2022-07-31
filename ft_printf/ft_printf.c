/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:27:13 by flazerak          #+#    #+#             */
/*   Updated: 2022/01/06 18:55:00 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_args(char c, va_list *args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar((unsigned char)va_arg(*args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
	{
		len += ft_putstr("0x");
		len += ft_point(va_arg(*args, unsigned long int), "0123456789abcdef");
	}
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (c == 'x')
		len += ft_hexa(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_hexa(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		len += ft_putchar ('%');
	else
		len += ft_putchar (c);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ptr;

	len = 0;
	i = 0;
	if (format[i] == '\0')
		return (len);
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		if (format[i] == '%')
		{
			if (!format[i + 1])
				break ;
			len += ft_print_args(format[i + 1], &ptr);
			i++;
		}
		i++;
	}
	va_end(ptr);
	return (len);
}
