/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:06:51 by eorer             #+#    #+#             */
/*   Updated: 2022/11/14 17:52:57 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (start > ft_strlen(s) - 1)
		str = (char *)malloc(1);
	else if (len > ft_strlen(s))
		str = (char *)malloc(ft_strlen(s) + 1);
	else
		str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
/*char	*ft_substr(char const *s, unsigned int start, size_t len)
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
}*/

/*int	main(void)
{
	char	*str;
	
	printf("len : %li\n", ft_strlen("tripouille"));
	str = ft_substr("1", 42, 4200000);
	printf("--> %s\n", str);
	free(str);
	return (0);
}*/
