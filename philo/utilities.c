/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:13:15 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/21 17:32:06 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	resultat;

	resultat = 0;
	neg = 1;
	while ((*nptr >= 8 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
	{
		neg = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr) && *nptr)
	{
		resultat = resultat * 10 + *nptr - '0';
		nptr++;
	}
	return (resultat * neg);
}

void	ft_bzero(void *s, size_t n)
{
	memset(s, 0, n);
}
