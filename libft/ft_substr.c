/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:06:51 by eorer             #+#    #+#             */
/*   Updated: 2022/11/11 15:14:51 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*sub;

	size = len;
	if (len > ft_strlen(s))
		size = ft_strlen(s);
	if (start > ft_strlen(s) - 1)
		size = 0;
	sub = (char *)malloc(size + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (s[i] && i < size)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub [i] = '\0';
	return (sub);
}

/*int	main(void)
{
	char	*str;
	
	printf("len : %li\n", ft_strlen("tripouille"));
	str = ft_substr("1", 42, 4200000);
	printf("--> %s\n", str);
	free(str);
	return (0);
}*/
