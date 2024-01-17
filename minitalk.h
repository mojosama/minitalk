/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:45:53 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/17 17:08:04 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>

int		ft_atoi(const char *str);

int		ft_printf(const char *format, ...);
int		ft_print_format(char type, va_list params);
size_t	ft_strlen(const char *str);

int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_printnbr(long n, char c);
int		ft_printpointer(unsigned long long n);
int		ft_printptr(unsigned long long n);

#endif