/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:28:13 by flazerak          #+#    #+#             */
/*   Updated: 2021/12/30 18:28:13 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	len = 0;
	while (str[i])
	{
		len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}
