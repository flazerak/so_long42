/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:27:01 by flazerak          #+#    #+#             */
/*   Updated: 2021/12/30 18:27:01 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_point(unsigned long n, const char *base)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += ft_point(n / 16, base);
		len += ft_point(n % 16, base);
	}
	else if (n < 16)
	{
		if (n > 9)
			len += ft_putchar(base[n]);
		else
			len += ft_putchar(base[n]);
	}
	return (len);
}
