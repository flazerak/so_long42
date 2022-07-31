/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:28:02 by flazerak          #+#    #+#             */
/*   Updated: 2021/12/30 18:28:02 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 0 && n < 10)
		len += ft_putchar(n + '0');
	else
	{
		len += ft_putnbr(n / 10);
		len += ft_putchar((n % 10) + '0');
	}
	return (len);
}
