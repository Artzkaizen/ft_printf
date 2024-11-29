/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:22:28 by chuezeri          #+#    #+#             */
/*   Updated: 2024/11/28 19:20:50 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>

int	print_hex(unsigned int value, int (*f)(int))
{
	int			i;
	char		temp;
	int			offset;
	char		buffer[16];
	const char	*hex_chars;

	i = 0;
	offset = 0;
	hex_chars = "0123456789ABCDEF";
	if (value == 0)
		buffer[offset++] = '0';
	else
	{
		while (value > 0)
		{
			buffer[offset++] = f(hex_chars[value % 16]);
			value /= 16;
		}
		while (i < offset / 2)
		{
			++i;
			temp = buffer[i];
			buffer[i] = buffer[offset - i - 1];
			buffer[offset - i - 1] = temp;
		}
	}
	buffer[offset] = '\0';
	return (ft_print_str_fd(buffer, STDOUT_FILENO));
}

int	ft_printf(const char *str, ...)
{
	size_t			i;
	va_list			args;
	static int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i + 1] && str[i] == '%' && ft_strchr("cspdiuxX", str[i + 1]))
		{
			if (str[i + 1] == 's')
				count += ft_print_str_fd(va_arg(args, char *), STDOUT_FILENO);
			else if (str[i + 1] == 'c')
				count += ft_print_char_fd(va_arg(args, int), STDOUT_FILENO);
			else if (str[i + 1] == 'i' || str[i + 1] == 'd')
				count += ft_putnbr_fd(va_arg(args, int), STDOUT_FILENO, 0);
			else if (str[i + 1] == 'u')
				count += ft_putnbr_fd(va_arg(args, int), STDOUT_FILENO, 1);
			else if (str[i + 1] == 'x')
				count += print_hex(va_arg(args, int), ft_tolower);
			else if (str[i + 1] == 'X')
				count += print_hex(va_arg(args, int), ft_toupper);
			else if (str[i + 1] == 'p')
				count += print_hex((va_arg(args, unsigned long long)), ft_toupper);
			i += 2;
		}
		else
			count += ft_print_char_fd(str[i++], STDOUT_FILENO);
	}
	va_end(args);
	return (count);
}
