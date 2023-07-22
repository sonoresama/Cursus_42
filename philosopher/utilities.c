/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:02:48 by eorer             #+#    #+#             */
/*   Updated: 2023/04/13 17:30:06 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

typedef long long int t_long;

int	ft_isdigit(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

t_long	ft_atoi(const char *nptr)
{
	t_long	neg;
	t_long	resultat;

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
	if (*nptr)
		return (0);
	return (resultat * neg);
}
