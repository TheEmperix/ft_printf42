/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:19:58 by woberon           #+#    #+#             */
/*   Updated: 2021/12/19 17:20:00 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr_fd(int n, int *fd);
void	ft_putstr_fd(char *s, int *fd);
void	ft_unsigned_int(unsigned int n, int *sum);
void	ft_put_hexadecimal(unsigned int number, int *sum, char c);
void	ft_put_address(unsigned long number, int *sum);
void	ft_putchar_fd(char c, int *fd);
int		ft_printf(const char *format, ...);
int		ft_puthex_up(unsigned long number, int is_pointer);

#endif
