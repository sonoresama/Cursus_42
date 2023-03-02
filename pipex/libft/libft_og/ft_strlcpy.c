/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:15:26 by eorer             #+#    #+#             */
/*   Updated: 2022/11/10 16:47:14 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	s;
	size_t	i;

	s = ft_strlen(src);
	if (s + 1 < size)
	{
		i = 0;
		while (i < s + 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else if (size)
	{
		i = 0;
		while (i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (s);
}

/*int	main(void)
{
	char	str[20];

	ft_strlcpy(str, "coucou", 6);
	printf("--> %s\n", str);
	return (0);
}*/
