/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:02:45 by eorer             #+#    #+#             */
/*   Updated: 2022/11/10 11:07:41 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	cast;

	cast = (char)(c % 256);
	i = ft_strlen(s);
	while (s[i] != cast && i > 0)
		i--;
	if (i == 0 && s[i] != cast)
		return (0);
	return ((char *)s + i);
}

/*int	main(void)
{
	char s1[] = "tripouille";
	char s2[] = "ltripouiel";
	char s3[] = "";

	printf("--> %s\n", (ft_strrchr(s1, 't')== s1) ? "OK" : "KO");
	printf("--> %s\n", (ft_strrchr(s1, 'l')== s1 + 8) ? "OK" : "KO");
	printf("--> %s\n", (ft_strrchr(s2, 'l')== s2 + 9) ? "OK" : "KO");
	printf("--> %s\n", (ft_strrchr(s1, 'z')== NULL) ? "OK" : "KO");
	printf("--> %s\n", (ft_strrchr(s1, 0)== s1 + ft_strlen(s1)) ? "OK" : "KO");
	printf("--> %s\n", (ft_strrchr(s1, 't' + 256)== s1) ? "OK" : "KO");
	char *empty = (char *)ft_calloc(1,1);
	printf("--> %s\n", (ft_strrchr(empty, 'V')== NULL) ? "OK" : "KO"); free(empty);
	printf("--> %s\n", (ft_strrchr(s3, 0)== s3) ? "OK" : "KO");
	return (0);
}*/
