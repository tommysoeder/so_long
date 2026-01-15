/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:10:52 by tomamart          #+#    #+#             */
/*   Updated: 2026/01/15 11:33:46 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdarg.h>

int	ft_handle_format(char specifier, va_list args);

int	ft_handle_string(va_list args);
int	ft_handle_char(va_list args);
int	ft_handle_integer(va_list args);
int	ft_handle_pointer(va_list args);
int	ft_handle_unsigned(va_list args);
int	ft_handle_hex_lower(va_list args);
int	ft_handle_hex_upper(va_list args);
int	ft_handle_percent(void);
int	ft_puthex_base_count(unsigned int n, char *base);

#endif
