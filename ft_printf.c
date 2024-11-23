/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:22:28 by chuezeri          #+#    #+#             */
/*   Updated: 2024/11/23 19:47:43 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	size_t	i;
	char	*s;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (i < 2)
	{
		s = va_arg(args, char *);
		ft_putstr_fd(s, 1);
	}
	return (0);
	va_end(args);
}
