/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:57:17 by hlopez            #+#    #+#             */
/*   Updated: 2023/11/20 15:57:45 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_print_format(char type, va_list params);

int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_printnbr(long n, char c);
int		ft_printpointer(unsigned long long n);
int		ft_printptr(unsigned long long n);

size_t	ft_strlen(const char *str);

#endif