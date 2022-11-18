/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:32:01 by eorer             #+#    #+#             */
/*   Updated: 2022/11/18 15:55:04 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "libftprintf.h"

void	ft_putchar_count_fd(char c, int fd, int *count)
{
	write(fd, &c, 1);
	*count = *count + 1;
}

void	ft_putnbr_count_fd(int n, int fd, int *count)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n / 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_count_fd(n % 10 + '0', fd, count);
}

void	ft_putstr_count_fd(char *str, int fd, int *count)
{
	write(fd, str, ft_strlen(str));
	*count += ft_strlen(str);
}
