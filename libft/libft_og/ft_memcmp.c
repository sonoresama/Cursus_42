/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:23:09 by eorer             #+#    #+#             */
/*   Updated: 2022/11/08 09:52:58 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n && *str1 == *str2)
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*str1 - *str2);
}

/*int	main()
{
	const char s1[] = "atoms\0\0\0\0";  // extra null bytes at end
	const char s2[] = "atoms\0abc";     // embedded null byte
	const char s3[] = "atomsaaa";

	printf("strcmp 1-2: %i\n", strcmp(s1, s2));
	printf("strcmp 1-3: %i\n", strcmp(s1, s3));
	printf("strncmp 1-3, 5: %i\n", strncmp(s1, s3, 5));
	printf("memcmp 1-3, 5: %i\n", memcmp(s1, s3, 5));
	printf("ft_memcmp 1-3, 5: %i\n", ft_memcmp(s1, s3, 5));
	printf("strncmp 1-2, 8: %i\n", strncmp(s1, s2, 8));
	printf("memcmp 1-2, 8: %i\n", memcmp(s1, s2, 8));
	printf("ft_memcmp 1-2, 8: %i\n", ft_memcmp(s1, s2, 8));
	return (0);
}*/
