/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:22:28 by chuezeri          #+#    #+#             */
/*   Updated: 2024/11/28 13:52:59 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>

void print_hex(unsigned int value, int (*f)(int), int *count)
{
	char buffer[16];
	const char *hex_chars;
	int offset = 0;

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
		for (int i = 0; i < offset / 2; ++i)
		{
			char temp = buffer[i];
			buffer[i] = buffer[offset - i - 1];
			buffer[offset - i - 1] = temp;
			count++;
		}
	}
	buffer[offset] = '\0';
	ft_print_str_fd(buffer, STDOUT_FILENO, count);
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
				ft_print_str_fd(va_arg(args, char *), STDOUT_FILENO, &count);
			else if (str[i + 1] == 'c')
				ft_print_char_fd(va_arg(args, int), STDOUT_FILENO, &count);
			else if (str[i + 1] == 'i' || str[i + 1] == 'd')
				ft_putnbr_fd(va_arg(args, int), STDOUT_FILENO, &count);
			else if (str[i + 1] == 'x' || str[i + 1] == 'X')
				print_hex(va_arg(args, int), ft_tolower, &count);
			else if (str[i + 1] == 'X')
				print_hex(va_arg(args, int), ft_toupper, &count);
			else if (str[i + 1] == 'p')
				ft_print_str_fd((va_arg(args, void *)), STDOUT_FILENO, &count);
			i += 2;
		}
		else
			ft_print_char_fd(str[i++], STDOUT_FILENO, &count);
	}
	va_end(args);
	return (count);
}
