/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:22:28 by chuezeri          #+#    #+#             */
/*   Updated: 2024/11/25 19:05:01 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

// TODO: parse the string
// TODO: get the format types passed in
// TODO: get the amount of args that are required

// typedef struct s_format_type
// {
// 	const char	*type;
// 	int			count;
// }	t_format_type;
// typedef struct s_format_args
// {
// 	int				arg_count;
// 	t_format_type	*arg_types;
// }	t_format_args;

// t_format_args	*ft_parse_str(const char *str)
// {
// 	size_t			i;
// 	t_format_args	format;
// 	t_format_type	*arg_types;

// 	i = 0;
// 	format.arg_count = 0;
// 	arg_types = (t_format_args *)malloc(sizeof(t_format_args));
// 	if (!arg_types)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		if (str[i] == '%' && str[i + 1] == 's')
// 			format.arg_count++;
// 		i++;
// 	}
// 	return (&format);
// }

// void	ft_format(const char *str, void (*f)(void *, int))
// {
// 	size_t	i;

// 	i = 0;
// 	if (str[i] == '%' && str[i + 1] == 's')
// 		{
// 			s = va_arg(args, char *);
// 			ft_putstr_fd(s, STDOUT_FILENO);
// 			i += 2;
// 		}

// }

void print_double(double value)
{
	int i;
	int digit;
	int offset;
	int int_len;
	char buffer[64];
	char int_str[32];
	int integer_part;
	int temp = integer_part;
	double fractional_part = value - integer_part;

	int_len = 0;
	integer_part = (int)value;
	if (fractional_part < 0)
		fractional_part = -fractional_part;

	offset = 0;
	if (value < 0)
	{
		buffer[offset++] = '-';
		integer_part = -integer_part;
	}
	if (temp == 0)
		int_str[int_len++] = '0';
	while (temp > 0)
	{
		int_str[int_len++] = '0' + (temp % 10);
		temp /= 10;
	}
	// Reverse the integer string and append to the buffer
	i = int_len - 1;
	while (i >= 0)
	{
		buffer[offset++] = int_str[i];
		i--;
	}
	// Add the decimal point
	buffer[offset++] = '.';
	// Convert fractional part to string (up to 6 decimal places)
	while (fractional_part > 0 && offset < sizeof(buffer) - 1)
	{
		fractional_part *= 10;
		digit = (int)fractional_part;
		buffer[offset++] = '0' + digit;
		fractional_part -= digit;
	}
	buffer[offset] = '\0';
	ft_putstr_fd(buffer, STDOUT_FILENO);
}

#include <unistd.h>

void print_hex(unsigned int value, int (*f)(int))
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
		}
	}
	buffer[offset] = '\0';
	ft_putstr_fd(buffer, STDOUT_FILENO);
}

int ft_printf(const char *str, ...)
{
	size_t i;
	va_list args;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX", str[i + 1]))
		{
			if (str[i + 1] == 's')
				ft_putstr_fd(va_arg(args, char *), STDOUT_FILENO);
			else if (str[i + 1] == 'c')
				ft_putchar_fd(va_arg(args, int), STDOUT_FILENO);
			else if (str[i + 1] == 'i' || str[i + 1] == 'd')
				ft_putnbr_fd(va_arg(args, int), STDOUT_FILENO);
			else if (str[i + 1] == 'p')
				ft_putstr_fd((va_arg(args, void *)), STDOUT_FILENO);
			else if (str[i + 1] == 'x')
				print_hex(va_arg(args, int), ft_tolower);
			else if (str[i + 1] == 'X')
				print_hex(va_arg(args, int), ft_toupper);
			i += 2;
		}
		else
			ft_putchar_fd(str[i++], STDOUT_FILENO);
	}
	va_end(args);
	return (0);
}
