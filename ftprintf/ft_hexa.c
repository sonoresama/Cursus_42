/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:03:07 by emileorer         #+#    #+#             */
/*   Updated: 2022/11/20 14:41:38 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	char	*dup;
	size_t	i;
	size_t	size;

	size = ft_strlen(str);
	i = 0;
	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[size - i - 1];
		i++;
	}
	return (dup);
}

static void	ft_putnbr_2nd_comp(int n, char *base, int fd, int *count, int compteur)
{
	if (compteur < 7)
		ft_putnbr_2nd_comp(n / 16, base, fd, count, compteur + 1);
	ft_putchar_count_fd(base[n % 16], fd, count);
}

void	ft_putnbr_hexa_fd(int n, char *base, int fd, int *count)
{
	if (n < 0)
	{
		n = -1 * n - 1;
		ft_putnbr_2nd_comp(n, ft_strrev(base), fd, count, 0);
		return ;
	}
	if (n / 16)
		ft_putnbr_hexa_fd(n / 16, base, fd, count);
	ft_putchar_count_fd(base[n % 16], fd, count);
}

static void	ft_puthexa_ul(unsigned long n, char *base, int fd, int *count)
{
	if (n / 16)
		ft_puthexa_ul(n / 16, base, fd, count);
	ft_putchar_count_fd(base[n % 16], fd, count);
}

void	ft_put_adress(void *ptr, int fd, int *count)
{
	unsigned long	adress;

	if (ptr)
	{
		adress = (unsigned long)ptr;
		ft_putstr_count_fd("0x", 1, count);
		ft_puthexa_ul(adress, "0123456789abcdef", fd, count);
	}
	else
		ft_putstr_count_fd("(nil)", 1, count);
}
