/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:51:52 by eorer             #+#    #+#             */
/*   Updated: 2022/11/10 10:54:03 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cast;

	cast = (char)(c % 256);
	i = 0;
	while (s[i] && s[i] != cast)
		i++;
	if (i == ft_strlen(s) && cast != 0)
		return (0);
	return ((char *)s + i);
}

/*int	main(void)
{
	char	s[] = "tripouille";

	printf("--> %s\n", (ft_strchr(s, 't') == s) ? "OK" : "KO");
	printf("--> %s\n", (ft_strchr(s, 'l') == s + 7) ? "OK" : "KO");
	printf("--> %s\n", (ft_strchr(s, 'z') == 0) ? "OK" : "KO");
	printf("--> %s\n", (ft_strchr(s, 0) == s + ft_strlen(s)) ? "OK" : "KO");
	printf("--> %s\n", (ft_strchr(s, 't' + 256) == s) ? "OK" : "KO");
	return (0);
}*/
