/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:28:48 by chuezeri          #+#    #+#             */
/*   Updated: 2024/11/25 19:12:21 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdarg.h>

int	main(void)
{
	ft_printf("Hello, %s! You have %d new messages.\n", "Alice", 5);
	ft_printf("%c\n", 't');
	ft_printf("%d\t->d\n", 2323);
	return (0);
}
