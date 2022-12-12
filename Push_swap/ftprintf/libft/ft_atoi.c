/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:09:56 by eorer             #+#    #+#             */
/*   Updated: 2022/12/12 18:59:42 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

/*int	main(int argc, char **argv)
{
	(void)argc;

	printf("atoi : %i\n", atoi(argv[1]));
	printf("ft_atoi : %lli\n", ft_atoi(argv[1]));
	return (0);
}*/
