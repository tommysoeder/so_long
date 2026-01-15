/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:32:39 by tomamart          #+#    #+#             */
/*   Updated: 2026/01/15 11:32:39 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_internal.h"
//#include "ft_printf.h"

int	ft_handle_hex_upper(va_list args)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	return (ft_puthex_base_count(x, "0123456789ABCDEF"));
}
