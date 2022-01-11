/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:23:31 by woberon           #+#    #+#             */
/*   Updated: 2021/12/19 17:23:33 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	translate(unsigned int n, int flag)
{
	if (n < 10)
		return ('0' + n);
	else if (n == 10)
		return ('A' + flag);
	else if (n == 11)
		return ('B' + flag);
	else if (n == 12)
		return ('C' + flag);
	else if (n == 13)
		return ('D' + flag);
	else if (n == 14)
		return ('E' + flag);
	else
		return ('F' + flag);
}

static void	write_number(unsigned int n, int *sum, int flag)
{
	char	s;

	if (n == 0)
		return ;
	else
	{
		write_number(n / 16, sum, flag);
		s = translate(n % 16, flag);
		*sum += write(1, &s, 1);
	}
}

void	ft_put_hexadecimal(unsigned int n, int *s, char c)
{
	int					flag;

	if (c == 'x')
		flag = 32;
	else
		flag = 0;
	if (n == 0)
		*s += write(1, "0", 1);
	else
		write_number(n, s, flag);
}
