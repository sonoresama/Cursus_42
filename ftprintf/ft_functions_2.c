/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:40:51 by eorer             #+#    #+#             */
/*   Updated: 2022/11/18 17:11:08 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_unsigned_putnbr_fd(unsigned int nbr, int fd, int *count)
{
	if (nbr / 10)
		ft_unsigned_putnbr_fd(nbr / 10, fd, count);
	ft_putchar_count_fd(nbr % 10 + '0', fd, count);
}

void	ft_putnbr_hexa_fd(int n, char *base, int fd, int *count)
{
	if (n == -2147483648)
	{
		write(fd, "-80000000", 9);
		*count = *count + 9;
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
		*count = *count + 1;
	}
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

	adress = (unsigned long)ptr;
	ft_putstr_count_fd("0x", 1, count);
	ft_puthexa_ul(adress, "0123456789abcdef", fd, count);
}
