/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:28:48 by chuezeri          #+#    #+#             */
/*   Updated: 2024/11/28 19:21:11 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdarg.h>

int	main(void)
{
	// ft_printf("Hello, %s! You have %d new messages.%\n", "Alice", 5);
	// printf("#");
	int num;
	num = 0;
	ft_printf("%p\n", &num);
	printf("%p\n", &num);
	ft_printf("%d\n", num);
	// printf("%p\n", (char *)NULL);
	// printf("words: %d\n", ft_printf("u-> %u\n", -255));
	return (0);
}
