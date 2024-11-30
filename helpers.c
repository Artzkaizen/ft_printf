/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:54:55 by chuezeri          #+#    #+#             */
/*   Updated: 2024/12/01 00:11:32 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	ft_print_char_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_print_str_fd(char *str, int fd)
{
	int	count;

	count = 0;
	if (!str)
		return (ft_print_str_fd("(null)", fd));
	while (*str)
	{
		count += ft_print_char_fd(*str, fd);
		str++;
	}
	return (count);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
