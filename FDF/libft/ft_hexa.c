/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:03:07 by emileorer         #+#    #+#             */
/*   Updated: 2022/11/28 14:06:03 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa_fd(unsigned int n, char *base, int fd, int *count)
{
	if (n / 16)
		ft_putnbr_hexa_fd(n / 16, base, fd, count);
	ft_putchar_count_fd(base[n % 16], fd, count);
}

static void	ft_puthexa_ul(unsigned long n, char *base, int fd, int *count)
{
	if (n / 16)
		ft_puthexa_ul(n / 16, base, fd, count);
	ft_putchar_count_fd(base[n % 16], fd, count);
}

void	ft_put_adress(void *ptr, int fd, int *count)
{
	unsigned long	adress;

	if (ptr)
	{
		adress = (unsigned long)ptr;
		ft_putstr_count_fd("0x", 1, count);
		ft_puthexa_ul(adress, "0123456789abcdef", fd, count);
	}
	else
		ft_putstr_count_fd("(nil)", 1, count);
}
