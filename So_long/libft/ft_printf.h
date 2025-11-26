/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:31:58 by tomamart          #+#    #+#             */
/*   Updated: 2025/05/23 12:31:59 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int ft_printf(const char *format, ...);
int	ft_handle_string(va_list args);
int	ft_handle_char(va_list args);
int	ft_handle_integer(va_list args);
int	ft_putnbr_count(unsigned int n);
int	ft_handle_unsigned(va_list args);
int	ft_putunbr_count(unsigned int n);
int ft_handle_hex_lower(va_list args);
int	ft_puthex_base_count(unsigned int n, char *base);
int ft_handle_hex_upper(va_list args);
int	ft_handle_pointer(va_list args);
int	ft_puthex_ptr(unsigned long n);
int ft_handle_format(char specifier, va_list args);
int ft_handle_percent(void);

#endif