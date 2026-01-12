/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:32:55 by tomamart          #+#    #+#             */
/*   Updated: 2026/01/12 14:11:50 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf_internal.h"

int	ft_handle_string(va_list args)
{
	char	*str;
	int		count;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	count = 0;
	while (str[count])
		write(1, &str[count++], 1);
	return (count);
}
