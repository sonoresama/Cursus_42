/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:09:56 by eorer             #+#    #+#             */
/*   Updated: 2022/11/07 16:29:35 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

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

/*int	main(int argc, char **argv)
{
	(void)argc;

	printf("atoi : %i\n", atoi(argv[1]));
	printf("ft_atoi : %i\n", ft_atoi(argv[1]));
	return (0);
}*/
