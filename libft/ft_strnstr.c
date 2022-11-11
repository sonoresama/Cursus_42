/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:53:19 by eorer             #+#    #+#             */
/*   Updated: 2022/11/10 11:41:30 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
//#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little == 0)
		return ((char *)big);
	if (*big == '\0' && *little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char *empty = (char*)"";
	printf("--> %s\n", (ft_strnstr(haystack, needle, 0) == 0) ? "OK" : "KO");
	printf("--> %s\n", (ft_strnstr(haystack, needle, -1) == 
	haystack + 1) ? "OK" : "KO");
	printf("--> %s\n", (ft_strnstr(haystack, 
	"a", -1) == haystack) ? "OK" : "KO"); 
	printf("--> %s\n", (ft_strnstr(haystack, "c", -1) == haystack 
	+ 4) ? "OK" : "KO"); 
	printf("--> %s\n", (ft_strnstr(empty, "", -1) == empty) ? "OK" : "KO"); 
	printf("--> %s\n", (ft_strnstr(empty, "", 0) == empty) ? "OK" : "KO"); 
	printf("--> %s\n", (ft_strnstr(empty, "coucou", -1) == 0) ? "OK" : "KO"); 
	printf("--> %s\n", (ft_strnstr(hayst
	ack, "aaabc", 5) == haystack) ? "OK" : "KO"); 
	printf("--> %s\n", (ft_strnstr(haystack, "
	abcd", 9) == haystack + 5) ? "OK" : "KO"); 
	printf("--> %s\n", (ft_strnstr(haystack, "cd", 8) == NULL) ? "OK" : "KO"); 
	printf("--> %s\n", (ft_strnstr(hayst
	ack, "a", 1) == haystack) ? "OK" : "KO"); 
	printf("--> %s\n", (ft_strnstr("1", "a", 1) == NULL) ? "OK" : "KO");
	printf("--> %s\n", (ft_strnstr("22", "b", 2) == NULL) ? "OK" : "KO");
	write(1, "\n", 1);
	return (0);
}*/
