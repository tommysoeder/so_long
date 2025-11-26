/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:32:55 by tomamart          #+#    #+#             */
/*   Updated: 2025/05/23 12:32:56 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_handle_string(va_list args)
{
	char *str;
	int	count;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	count = 0;
	while (str[count])
		write(1, &str[count++], 1);
	return(count);
}