/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:28:48 by chuezeri          #+#    #+#             */
/*   Updated: 2024/11/30 23:47:47 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int	main(void)
{
	 // Basic string tests
    printf("--- String Tests ---\n");
    printf("Standard printf: [%s]\n", "Hello, World!");
    ft_printf("Custom ft_printf: [%s]\n", "Hello, World!");

    // Character tests
    printf("\n--- Character Tests ---\n");
    printf("Standard printf: [%c][%c][%c]\n", 'A', '0', 127);
    ft_printf("Custom ft_printf: [%c][%c][%c]\n", 'A', '0', 127);

    // Integer tests (decimal)
    printf("\n--- Integer (Decimal) Tests ---\n");
    printf("Standard printf: [%d][%i][%d][%d]\n", 0, -42, 42, INT_MAX);
    ft_printf("Custom ft_printf: [%d][%i][%d][%d]\n", 0, -42, 42, INT_MAX);
    
    printf("Standard printf: [%d]\n", INT_MIN);
    ft_printf("Custom ft_printf: [%d]\n", INT_MIN);

    // Unsigned integer tests
    printf("\n--- Unsigned Integer Tests ---\n");
    printf("Standard printf: [%u][%u][%u]\n", 0, 42, UINT_MAX);
    ft_printf("Custom ft_printf: [%u][%u][%u]\n", 0, 42, UINT_MAX);

    // Hexadecimal tests (lowercase)
    printf("\n--- Hexadecimal (Lowercase) Tests ---\n");
    printf("Standard printf: [%x][%x][%x]\n", 0, 42, UINT_MAX);
    ft_printf("Custom ft_printf: [%x][%x][%x]\n", 0, 42, UINT_MAX);

    // Hexadecimal tests (uppercase)
    printf("\n--- Hexadecimal (Uppercase) Tests ---\n");
    printf("Standard printf: [%X][%X][%X]\n", 0, 42, UINT_MAX);
    ft_printf("Custom ft_printf: [%X][%X][%X]\n", 0, 42, UINT_MAX);

    // Pointer tests
    printf("\n--- Pointer Tests ---\n");
    int x = 42;
    printf("Standard printf: [%p][%p]\n", (void*)0, (void*)&x);
    ft_printf("Custom ft_printf: [%p][%p]\n", (void*)0, (void*)&x);

    // Mixed format tests
    printf("\n--- Mixed Format Tests ---\n");
    printf("Standard printf: [%s][%d][%x][%c]\n", "Hello", 42, 255, 'A');
    ft_printf("Custom ft_printf: [%s][%d][%x][%c]\n", "Hello", 42, 255, 'A');

    // Edge case tests
    printf("\n--- Edge Case Tests ---\n");
    printf("Standard printf: [%%][%% ][%%s]\n");
    ft_printf("Custom ft_printf: [%%][%% ][%%s]\n");

    // Long string with multiple formats
    printf("\n--- Complex Format Test ---\n");
    printf("Standard printf: Number: %d, Hex: %x, String: %s, Char: %c, Unsigned: %u\n", 
           -12345, 0xABCD, "Test", 'Z', 54321U);
    ft_printf("Custom ft_printf: Number: %d, Hex: %x, String: %s, Char: %c, Unsigned: %u\n", 
              -12345, 0xABCD, "Test", 'Z', 54321U);

    // Null string test
    printf("\n--- Null String Test ---\n");
    printf("Standard printf: [%s]\n", NULL);
    ft_printf("Custom ft_printf: [%s]\n", NULL);
    // Null char test
    printf("\n--- Null char Test ---\n");
    printf("Standard printf: [%c]\n", NULL);
    ft_printf("Custom ft_printf: [%c]\n", NULL);

    printf("\n--- Null Pointer Test ---\n");
    printf("Standard printf: [%p]\n", NULL);
    ft_printf("Custom ft_printf: [%p]\n", NULL);
	return (0);
}
