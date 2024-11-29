/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:32:58 by chuezeri          #+#    #+#             */
/*   Updated: 2024/11/28 19:13:53 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

int	ft_putnbr_fd(int n, int fd, int sign)
{
	long	num;
	int		count;

	count = 0;
	if (sign)
		num = (unsigned int)n;
	else
		num = n;
	if (num < 0)
	{
		count += ft_print_char_fd('-', fd);
		num *= -1;
	}
	if (num >= 10)
	{
		count += ft_putnbr_fd(num / 10, fd, sign);
		count += ft_print_char_fd((num % 10) + '0', fd);
	}
	else
		count += ft_print_char_fd(num + '0', fd);
	return (count);
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
