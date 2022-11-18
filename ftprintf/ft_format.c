/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:39:26 by eorer             #+#    #+#             */
/*   Updated: 2022/11/18 16:09:09 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "libftprintf.h"

static void	ft_print_arg(va_list arg, char c, int *count);

static int	isformat(char c)
{
	char	*format;
	int		i;

	format = "idscuxXp%";
	i = 0;
	while (format[i] && format[i] != c)
		i++;
	if (i == 9)
		return (0);
	return (1);
}

int	ft_format(va_list arg, char *str, int *count)
{
	int	i;

	i = 0;
	if (isformat(str[i]))
		ft_print_arg(arg, str[i], count);
	return (i);
}

static void	ft_print_arg(va_list arg, char c, int *count)
{
	if (c == 'i' || c == 'd')
		ft_putnbr_count_fd(va_arg(arg, int), 1, count);
	else if (c == 's')
		ft_putstr_count_fd(va_arg(arg, char *), 1, count);
	else if (c == 'c')
		ft_putchar_count_fd(va_arg(arg, int), 1, count);
	else if (c == 'u')
		ft_unsigned_putnbr_fd(va_arg(arg, unsigned int), 1, count);
	else if (c == 'x')
		ft_putnbr_hexa_fd(va_arg(arg, int), "0123456789abcdef", 1, count);
	else if (c == 'X')
		ft_putnbr_hexa_fd(va_arg(arg, int), "0123456789ABCDEF", 1, count);
	else if (c == '%')
		ft_putchar_count_fd('%', 1, count);
	else if (c == 'p')
		ft_put_adress(va_arg(arg, void *), 1, count);
	else
		return ;
}
