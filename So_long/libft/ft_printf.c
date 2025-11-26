/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 00:00:00 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/24 00:00:00 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

static int	ft_putchar_count(char c)
{
	return (write(1, &c, 1));
}

static int	ft_putstr_count(char *s)
{
	int	len;

	if (!s)
		return (write(1, "(null)", 6));
	len = 0;
	while (s[len])
		len++;
	return (write(1, s, len));
}

static int	ft_putnbr_rec(long n)
{
	char	c;
	int		count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_rec(n / 10);
	c = '0' + (n % 10);
	count += write(1, &c, 1);
	return (count);
}

static int	ft_putunbr_rec(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr_rec(n / 10);
	c = '0' + (n % 10);
	count += write(1, &c, 1);
	return (count);
}

static int	ft_puthex_rec(unsigned long n, int upper)
{
	char		*base;
	int			count;

	base = upper ? "0123456789ABCDEF" : "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_rec(n / 16, upper);
	count += write(1, &base[n % 16], 1);
	return (count);
}

static int	ft_handle_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_count(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_count(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_rec((long)va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr_rec(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex_rec(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex_rec(va_arg(args, unsigned int), 1));
	else if (c == 'p')
	{
		void			*ptr;
		unsigned long	addr;
		int				count;

		ptr = va_arg(args, void *);
		if (!ptr)
			return (write(1, "(nil)", 5));
		addr = (unsigned long)ptr;
		count = write(1, "0x", 2);
		count += ft_puthex_rec(addr, 0);
		return (count);
	}
	else if (c == '%')
		return (ft_putchar_count('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += ft_handle_format(format[i], args);
		}
		else
			len += ft_putchar_count(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
