/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:28:25 by eorer             #+#    #+#             */
/*   Updated: 2022/11/09 15:52:47 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*src;
	size_t	i;

	i = 0;
	src = s;
	while (i < n)
	{
		src[i] = c;
		i++;
	}
	return (s);
}

/*int	main(int argc, char **argv)
{
	int	i;
	char	src[100];

	(void)argc;
	i = 0;
	ft_memset(src, 'A', ft_atoi(argv[1]));
	while (i < ft_atoi(argv[1]))
	{
		printf("--> %i\n", src[i]);
		i++;
	}
	return (0);
}*/
