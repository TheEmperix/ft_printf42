/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:20:42 by woberon           #+#    #+#             */
/*   Updated: 2021/12/19 17:20:44 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static void	check_format(int i, va_list arg, int *s, const char *format)
{
	if (format[i] == 'c')
		ft_putchar_fd((char)va_arg(arg, int), s);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr_fd(va_arg(arg, int), s);
	else if (format[i] == 's')
		ft_putstr_fd((char *)va_arg(arg, void *), s);
	else if (format[i] == '%')
		*s += write(1, &format[i], 1);
	else if (format[i] == 'u')
		ft_unsigned_int(va_arg(arg, unsigned int), s);
	else if (format[i] == 'p')
		ft_put_address((unsigned long)va_arg(arg, void *), s);
	else if (format[i] == 'x' || format[i] == 'X')
		ft_put_hexadecimal(va_arg(arg, unsigned int), s, format[i]);
}

int	ft_printf(const char *format, ...)
{
	int		s;
	int		i;
	va_list	arg;

	i = 0;
	s = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
			check_format(++i, arg, &s, format);
		else
			s += write (1, &format[i], 1);
		i++;
	}
	va_end(arg);
	return (s);
}
