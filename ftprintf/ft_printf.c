/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:34:13 by eorer             #+#    #+#             */
/*   Updated: 2022/11/15 17:53:13 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	int	i;
	int	j;
	char	*sub_str;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			sub_str = ft_substr(str, j, i - j - 1);
			ft_putstr_fd(sub_str, 1);
			free(sub_str);
			function = 
			/*if (str[i] == 'i')
				ft_putnbr_fd(va_arg(arg, int), 1);*/
			j = i + 1;
		}
		i++;
	}
	va_end(arg);
	sub_str = ft_substr(str, j, i - j);
	ft_putstr_fd(sub_str, 1);
	free(sub_str);
	return (0);
}

int	main(void)
{
	ft_printf("J'ai %i ans !", 24);
	return (0);
}
