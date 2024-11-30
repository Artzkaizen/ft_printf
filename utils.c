/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:32:58 by chuezeri          #+#    #+#             */
/*   Updated: 2024/12/01 00:12:17 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

static int	ft_is_valid_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i + 1] && str[i])
	{
		if (str[i] == '-' || str[i] == '+' || (str[i] == ' '
				|| (str[i] >= '\t' && str[i] <= '\r')))
			return (0);
		j = i + 1;
		while (str[i] && str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (++i);
}

int	ft_putnbr_base(int num, char *base, int sign)
{
	long		nbr;
	int			radix;
	static int	count;

	if (sign)
		nbr = (unsigned int)num;
	else
		nbr = num;
	radix = ft_is_valid_base(base);
	if (radix > 1)
	{
		if (nbr >= radix)
			ft_putnbr_base(nbr / radix, base, sign);
		else if (nbr < 0)
		{
			count += ft_print_char_fd('-', STDOUT_FILENO);
			if (nbr <= -radix)
				ft_putnbr_base(((nbr / radix) * -1), base, sign);
			nbr = (nbr % radix) * -1;
		}
		count += ft_print_char_fd(base[nbr % radix], STDOUT_FILENO);
	}
	return (count);
}

int	ft_putnbr_base_ul(unsigned long num, char *base)
{
	int			radix;
	static int	count;

	count = 0;
	radix = ft_is_valid_base(base);
	if (radix > 1)
	{
		if (num >= (unsigned long)radix)
			ft_putnbr_base_ul(num / radix, base);
		count += ft_print_char_fd(base[num % radix], STDOUT_FILENO);
	}
	return (count);
}
