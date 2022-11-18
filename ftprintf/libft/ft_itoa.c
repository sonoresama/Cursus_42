/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:08:42 by eorer             #+#    #+#             */
/*   Updated: 2022/11/11 14:41:20 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	size_nbr(int n)
{
	int		size;
	long	num;

	num = (long)n;
	size = 1;
	if (num < 0)
	{
		num = -num;
		size++;
	}
	while (num / 10)
	{
		num = num / 10;
		size++;
	}
	return (size);
}

static int	conversion(int n, char *resultat, int pos)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		num = -num;
		resultat[0] = '-';
	}
	if (num / 10)
		conversion(num / 10, resultat, pos - 1);
	resultat[pos] = num % 10 + '0';
	return (0);
}

char	*ft_itoa(int n)
{
	char	*resultat;

	resultat = malloc(size_nbr(n) + 1);
	if (!resultat)
		return (NULL);
	conversion(n, resultat, size_nbr(n) - 1);
	resultat[size_nbr(n)] = '\0';
	return (resultat);
}

/*int	main(int argc, char **argv)
{
	char	*str;

	(void)argc;
	str = ft_itoa(ft_atoi(argv[1]));
	printf("Size --> %i\n", size_nbr(ft_atoi(argv[1])));
	printf("--> %s\n", str);
	printf("Len --> %ld\n", ft_strlen(str));
	free(str);
	return (0);
}*/
