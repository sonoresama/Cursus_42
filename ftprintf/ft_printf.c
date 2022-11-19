/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:34:13 by eorer             #+#    #+#             */
/*   Updated: 2022/11/19 13:17:14 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

static void	print_substr(const char *str, int j, int i, int *count)
{
	char	*sub_str;

	sub_str = ft_substr(str, j, i);
	ft_putstr_count_fd(sub_str, 1, count);
	free(sub_str);
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
			i = i + ft_format(arg, (char *)&str[i], &count) + 1;
			j = i;
		}
		else
			i++;
	}
	va_end(arg);
	print_substr(str, j, i - j, &count);
	return (count);
}
