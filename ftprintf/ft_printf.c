/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:34:13 by eorer             #+#    #+#             */
/*   Updated: 2022/11/17 17:44:25 by eorer            ###   ########.fr       */
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
			ft_putstr_fd(ft_substr(str, j, i - j - 1), 1);
			free(ft_substr(str, j, i - j - 1));
			ft_format(arg, str[i]);
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
	void	*ptr;
	int	a;

	ptr = &a;
	ft_printf("J'ai %i ans ! En hexa ca fait %x ans! Et je m'appelle %s\n", 24, 24, "Tito");
	printf-O("J'ai %i ans ! En hexa ca fait %x ans! Et je m'appelle %s\n", 24, 24, "Tito");
	//ft_printf("\nTest : %p\n", ptr);
	printf("\nTest : %p\n", ptr);
	return (0);
}
