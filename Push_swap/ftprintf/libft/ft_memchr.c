/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:10:56 by eorer             #+#    #+#             */
/*   Updated: 2022/11/10 10:57:46 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	cast;
	size_t	i;

	str = (char *)s;
	cast = (char)(c % 256);
	i = 0;
	while (i < n && str[i] != cast)
		i++;
	if (i == n)
		return (NULL);
	return (str + i);
}

/*int	main()
{
	char	s[] = {0, 1, 2, 3, 4, 5};

	printf("--> %s\n", (ft_memchr(s, 0, 0) == 0) ? "OK" : "KO");
	printf("--> %s\n", (ft_memchr(s, 0, 1) == s) ? "OK" : "KO");
	printf("--> %s\n", (ft_memchr(s, 2, 3) == s + 2) ? "OK" : "KO");
	printf("--> %s\n", (ft_memchr(s, 6, 6) == 0) ? "OK" : "KO");
	printf("--> %s\n", (ft_memchr(s, 2 + 256, 3) == s + 2) ? "OK" : "KO");
	return (0);
}*/
