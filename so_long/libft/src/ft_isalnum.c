/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:15:39 by eorer             #+#    #+#             */
/*   Updated: 2022/11/07 12:24:27 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*int	main(int argc, char **argv)
{
	(void)argc;

	printf("return : %i\n", ft_isalnum((unsigned char)argv[1][0]));
	printf("digit : %i\n", ft_isdigit((unsigned char)argv[1][0]));
	printf("alpha : %i\n", ft_isalpha((unsigned char)argv[1][0]));
	return(0);
}*/
