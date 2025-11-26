/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:32:58 by tomamart          #+#    #+#             */
/*   Updated: 2025/05/23 12:32:59 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdarg.h>
#include <unistd.h>

int	ft_putunbr_count(unsigned int n)
{
	int count = 0;
	char c;

	if (n >= 10)
		count += ft_putunbr_count(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (count + 1);
}

int	ft_handle_unsigned(va_list args)
{
	unsigned int	u;
				
	u = va_arg(args, unsigned int);
	return (ft_putunbr_count(u));
}
