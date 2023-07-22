/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:34:13 by eorer             #+#    #+#             */
/*   Updated: 2022/12/16 13:41:03 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	print_substr(const char *str, int j, int i, int *count)
{
	char	*sub_str;

	sub_str = ft_substr(str, j, i);
	ft_putstr_count_fd(sub_str, 1, count);
	free(sub_str);
}

void	ft_print_arg(va_list arg, char c, int *count)
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

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		j;
	int		count;

	va_start(arg, str);
	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_substr(str, j, i - j - 1, &count);
			ft_print_arg(arg, str[i], &count);
			i++;
			j = i;
		}
		else
			i++;
	}
	va_end(arg);
	print_substr(str, j, i - j, &count);
	return (count);
}
