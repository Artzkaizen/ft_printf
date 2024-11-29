/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:00:16 by chuezeri          #+#    #+#             */
/*   Updated: 2024/11/28 15:30:51 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>

int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
char	*ft_strchr(const char *s, int c);
int		ft_print_char_fd(char c, int fd);
int		ft_print_str_fd(char *str, int fd);
int		ft_putnbr_fd(int n, int fd, int sign);

#endif