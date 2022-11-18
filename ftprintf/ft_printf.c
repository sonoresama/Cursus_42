/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:34:13 by eorer             #+#    #+#             */
/*   Updated: 2022/11/18 16:15:20 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "libftprintf.h"
#include <stdio.h>

static void	print_substr(const char *str, int j, int i, int *count)
{
	char *sub_str;
	
	sub_str = ft_substr(str, j, i);
	ft_putstr_count_fd(sub_str, 1, count);
	free(sub_str);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	j;
	int	count;
	va_list	arg;

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
	return (count + 1);
}

int	main(void)
{
	ft_putchar_fd('\n', 1);
	/*a = ft_printf("%s %i %s", "Hello j'ai", 24, "annees");
	ft_printf("Taille ft_printf : %i\n", a);
	ft_putchar_fd('\n', 1);
	b = printf("%s %i %s", "Hello j'ai", 24, "annees");
	printf("Taille printf : %i\n", b);*/
	printf("n --> %15i\n0 --> %015i\n  --> % 15i\n- --> %-15i\n+ --> %+15i\n. --> %.15i\n\n", -42, -42, -42, -42, -42, -42);
	printf("n --> %15i\n0 --> %015i\n  --> % 15i\n- --> %-15i\n+ --> %+15i\n. --> %.15i\n", 42, 42, 42, 42, 42, 42);
	return (0);
}
