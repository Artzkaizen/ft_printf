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

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 's')
		{
			ft_putstr_fd(va_arg(args, char *), STDOUT_FILENO);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 'c')
		{
			ft_putchar_fd(va_arg(args, int), STDOUT_FILENO);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 'd')
		{
			ft_putnbr_fd(va_arg(args, int), STDOUT_FILENO);
			i += 2;
		}
		else
			ft_putchar_fd(str[i++], STDOUT_FILENO);
	}
	va_end(args);
	return (0);
}
