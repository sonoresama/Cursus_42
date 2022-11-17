/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:39:26 by eorer             #+#    #+#             */
/*   Updated: 2022/11/17 17:43:13 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "libftprintf.h"

void	ft_format(va_list arg, char c)
{
	if (c == 'i' || c == 'd')
		ft_putnbr_fd(va_arg(arg, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(arg, char *), 1);
	else if (c == 'c')
		ft_putchar_fd(va_arg(arg, int), 1);
	else if (c == 'u')
		ft_unsigned_putnbr_fd(va_arg(arg, unsigned int), 1);
	else if (c == 'x')
		ft_putstr_fd(ft_hexa(va_arg(arg, int), "0123456789abcdef"), 1);
	else if (c == 'X')
		ft_putstr_fd(ft_hexa(va_arg(arg, int), "0123456789ABCDEF"), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	/*else if (c == 'p')
		ft_putstr_fd(ft_hexa(va_arg(arg, void *), "0123456789abcdef"), 1);*/
	else
		return;
}
