/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:32:42 by tomamart          #+#    #+#             */
/*   Updated: 2026/01/12 14:15:39 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_putnbr_count(unsigned int n)
{
	int		count;
	long	nb;
	char	c;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb >= 10)
		count += ft_putnbr_count(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_handle_integer(va_list args)
{
	int	d;

	d = va_arg(args, int);
	return (ft_putnbr_count(d));
}
