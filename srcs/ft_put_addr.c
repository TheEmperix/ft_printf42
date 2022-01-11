/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:23:12 by woberon           #+#    #+#             */
/*   Updated: 2021/12/19 17:23:14 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	translate_p(unsigned int n)
{
	if (n < 10)
		return ('0' + n);
	else if (n == 10)
		return ('a');
	else if (n == 11)
		return ('b');
	else if (n == 12)
		return ('c');
	else if (n == 13)
		return ('d');
	else if (n == 14)
		return ('e');
	else
		return ('f');
}

static void	write_number_p(unsigned long n, int *sum)
{
	char	s;

	if (n == 0)
		return ;
	else
	{
		write_number_p(n / 16, sum);
		s = translate_p(n % 16);
		*sum += write(1, &s, 1);
	}
}

void	ft_put_address(unsigned long n, int *s)
{
	*s += write(1, "0x", 2);
	if (n == 0)
		*s += write(1, "0", 1);
	else
		write_number_p(n, s);
}
