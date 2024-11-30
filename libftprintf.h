/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:00:16 by chuezeri          #+#    #+#             */
/*   Updated: 2024/12/01 00:07:10 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>

typedef unsigned int	t_u_int;

int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
char	*ft_strchr(const char *s, int c);
int		ft_print_char_fd(char c, int fd);
int		ft_print_str_fd(char *str, int fd);
int		ft_print_ptr(void *ptr, char *base);
int		ft_putnbr_fd(int n, int fd, int sign);
int		ft_putnbr_base(int num, char *base, int sign);
int		ft_putnbr_base_ul(unsigned long num, char *base);

#endif