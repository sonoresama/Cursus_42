/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:40:51 by eorer             #+#    #+#             */
/*   Updated: 2022/11/17 17:14:06 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "libftprintf.h"

static int	size_nbr(int n);
static int	conversion(int nbr, char *resultat, char *base, int pos);

void	ft_unsigned_putnbr_fd(unsigned int nbr, int fd)
{
	if (nbr / 10)
		ft_unsigned_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}

char	*ft_hexa(int nbr, char *base)
{
	char	*resultat;

	resultat = malloc(size_nbr(nbr) + 1);
	if (!resultat)
		return (NULL);
	conversion(nbr, resultat, base, size_nbr(nbr) - 1);
	resultat[size_nbr(nbr)] = '\0';
	return (resultat);
}

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
	while (num / 16)
	{
		num = num / 16;
		size++;
	}
	return (size);
}

static int	conversion(int nbr, char *resultat, char *base, int pos)
{
	long	num;

	num = (long)nbr;
	if (num < 0)
	{
		num = -num;
		resultat[0] = '-';
	}
	if (num / 16)
		conversion(num / 16, resultat, base, pos - 1);
	resultat[pos] = base[num % 16];
	return (0);
}

