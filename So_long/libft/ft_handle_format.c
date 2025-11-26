/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:31:52 by tomamart          #+#    #+#             */
/*   Updated: 2025/05/23 12:31:53 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_handle_format(char specifier, va_list args)
{
	if (specifier == 's')
		return (ft_handle_string(args));
	else if (specifier == 'c')
		return (ft_handle_char(args));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_handle_integer(args));
	else if (specifier == 'p')
		return (ft_handle_pointer(args));
	else if (specifier == 'u')
		return (ft_handle_unsigned(args));
	else if (specifier == 'x')
		return (ft_handle_hex_lower(args));
	else if (specifier == 'X')
		return (ft_handle_hex_upper(args));
	else if (specifier == '%')
		return (ft_handle_percent());
	return (0);
}
