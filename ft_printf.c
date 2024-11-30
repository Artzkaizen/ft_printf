/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:22:28 by chuezeri          #+#    #+#             */
/*   Updated: 2024/12/01 00:12:22 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>

#define DEC_BASE "0123456789"
#define HEX_BASE_UPP "0123456789ABCDEF"
#define HEX_BASE_LOW "0123456789abcdef"

int	ft_print_ptr(void *ptr, char *base)
{
	ft_print_str_fd("0x", STDOUT_FILENO);
	return (ft_putnbr_base_ul((unsigned long)ptr, base));
}

int	format_string(va_list *args, char c)
{
	if (c == 's')
		return (ft_print_str_fd(va_arg(*args, char *), STDOUT_FILENO));
	else if (c == 'c')
		return (ft_print_char_fd(va_arg(*args, int), STDOUT_FILENO));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_base(va_arg(*args, int), DEC_BASE, 0));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(*args, int), DEC_BASE, 1));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(*args, t_u_int), HEX_BASE_LOW, 1));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(*args, t_u_int), HEX_BASE_UPP, 1));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(*args, void *), HEX_BASE_LOW));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t		i;
	va_list		args;
	static int	c;

	i = 0;
	c = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i + 1] && str[i] == '%' && ft_strchr("cspdiuxX", str[i + 1]))
		{
			c += format_string(&args, str[i + 1]);
			i += 2;
		}
		else
			c += ft_print_char_fd(str[i++], STDOUT_FILENO);
	}
	va_end(args);
	return (c);
}
