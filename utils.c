/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:32:58 by chuezeri          #+#    #+#             */
/*   Updated: 2024/11/28 13:55:02 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_char_fd(char c, int fd, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}

void	ft_print_str_fd(char *str, int fd, int *count)
{
	while (*str)
	{
		ft_print_char_fd(*str, fd, count);
		str++;
	}
}

void	ft_putnbr_fd(int n, int fd, int *count)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_print_char_fd('-', fd, count);
		num *= -1;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd, count);
		ft_print_char_fd((num % 10) + '0', fd, count);
	}
	else
		ft_print_char_fd(num + '0', fd, count);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str || *str == (unsigned char)c)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}


size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
