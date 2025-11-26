/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:32:36 by tomamart          #+#    #+#             */
/*   Updated: 2025/05/23 12:32:37 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_handle_hex_lower(va_list args)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	return (ft_puthex_base_count(x, "0123456789abcdef"));
}
