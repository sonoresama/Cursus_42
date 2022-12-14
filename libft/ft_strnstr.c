/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:35:08 by eorer             #+#    #+#             */
/*   Updated: 2022/11/23 13:38:30 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big && len == 0)
		return (0);
	if (ft_strlen(little) == 0)
		return ((char *)&big[i]);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (i + j < len && big[i + j] == little[j])
			{
				j++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}

/*char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big || !little)
		return (NULL);
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

if (little == 0)
	return ((char *)big);

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("bsd --> %s\n", strnstr(argv[1], argv[2], ft_atoi(argv[3])));
	printf("mine --> %s\n", ft_strnstr(argv[1], argv[2], ft_atoi(argv[3])));
	printf("mine --> %s\n", ft_strnstr("", NULL, 3));
	printf("bsd --> %s\n", strnstr("", NULL, 3));
	
	return (0);
}*/
