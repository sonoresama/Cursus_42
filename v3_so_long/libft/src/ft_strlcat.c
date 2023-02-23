/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:20:18 by eorer             #+#    #+#             */
/*   Updated: 2022/11/19 19:12:49 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size <= ft_strlen(dest))
		return (ft_strlen(src) + size);
	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0' && j < (size - i - 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (ft_strlen(src) + i);
}

/*int	main(void)
{
	printf("--> %li\n", strlcat("Hello", "coucou", 4));
	printf("--> %li\n", ft_strlcat("Hello", "coucou", 4));
	return (0);
}*/
