/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:18:17 by rrakman           #+#    #+#             */
/*   Updated: 2023/04/21 21:58:20 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putnbr(int n)
{
	long	num;
	int		count;

	count = 0;
	num = n;
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	if (num < 10)
		count += ft_putchar(num + '0');
	else
	{
		count += ft_putnbr(num / 10);
		count += ft_putnbr(num % 10);
	}
	return (count);
}

unsigned long	ft_putunsigned(unsigned long n)
{
	long			num;
	unsigned long	count;

	count = 0;
	num = n;
	if (num < 10)
		count += ft_putchar(num + '0');
	else
	{
		count += ft_putunsigned(num / 10);
		count += ft_putunsigned(num % 10);
	}
	return (count);
}
