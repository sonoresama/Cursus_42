/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:32:01 by eorer             #+#    #+#             */
/*   Updated: 2022/12/16 13:56:41 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count_fd(char c, int fd, int *count)
{
	ft_putchar_fd(c, fd);
	*count = *count + 1;
}

void	ft_putnbr_count_fd(int n, int fd, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr_count_fd("-2147483648", fd, count);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_count_fd('-', fd, count);
	}
	if (n / 10)
		ft_putnbr_count_fd(n / 10, fd, count);
	ft_putchar_count_fd(n % 10 + '0', fd, count);
}

void	ft_putstr_count_fd(char *str, int fd, int *count)
{
	if (str)
	{
		ft_putstr_fd(str, fd);
		*count += ft_strlen(str);
	}
	else
		ft_putstr_count_fd("(null)", fd, count);
}

void	ft_unsigned_putnbr_fd(unsigned int nbr, int fd, int *count)
{
	if (nbr / 10)
		ft_unsigned_putnbr_fd(nbr / 10, fd, count);
	ft_putchar_count_fd(nbr % 10 + '0', fd, count);
}
