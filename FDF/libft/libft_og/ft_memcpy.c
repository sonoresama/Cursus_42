/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:54:35 by eorer             #+#    #+#             */
/*   Updated: 2022/11/11 10:39:48 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*dst;

	if (!dest && !src)
		return (dest);
	dst = dest;
	s = src;
	while (n)
	{
		*dst = *s;
		dst++;
		s++;
		n--;
	}
	return (dest);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	char	*dest;
	char	*dest2;

	dest = malloc(sizeof(dest) * 20);
	dest2 = malloc(sizeof(dest) * 20);
	printf("avant : %s\n", dest);
	ft_memcpy(dest, argv[1], ft_atoi(argv[2]));
	memcpy(dest2, argv[1], ft_atoi(argv[2]));
	printf("ft_memcpy : %s\n", dest);
	printf("memcpy : %s\n", dest);
	free(dest);
	free(dest2);
	return (0);
}*/
