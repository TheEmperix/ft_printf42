/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:23:46 by woberon           #+#    #+#             */
/*   Updated: 2021/12/19 17:23:48 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int *fd)
{
	char	c;

	if (n == -2147483648)
	{
		*fd += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		*fd += write(1, "-", 1);
	}
	if (n < 10)
	{
		c = n + '0';
		*fd += write(1, &c, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

void	ft_unsigned_int(unsigned int n, int *fd)
{
	unsigned int	new_n;
	char			c;

	if (n == 0)
	{
		*fd += write (1, "0", 1);
		return ;
	}
	new_n = n;
	if (new_n < 10)
	{
		c = new_n + '0';
		*fd += write(1, &c, 1);
	}
	else
	{
		ft_unsigned_int(n / 10, fd);
		ft_unsigned_int(n % 10, fd);
	}
}
