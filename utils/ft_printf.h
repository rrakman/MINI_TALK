/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 01:49:07 by rrakman           #+#    #+#             */
/*   Updated: 2023/04/21 21:57:57 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>

int				ft_printf(const char *format, ...);
int				ft_putchar(char c);
int				ft_strlen(const char *s);
int				ft_putstr(char *s);
int				ft_putnbr(int n);
int				ft_printhex(unsigned long nb, char c);
int				ft_hex(unsigned long num, char c);
int				ft_putptr(void *ptr);
int				ft_handle(va_list args, char c);
unsigned long	ft_putunsigned(unsigned long n);

#endif