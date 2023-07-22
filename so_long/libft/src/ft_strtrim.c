/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:40:33 by eorer             #+#    #+#             */
/*   Updated: 2022/11/11 14:42:08 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	deb;
	size_t	fin;
	size_t	i;
	char	*str;

	deb = 0;
	fin = ft_strlen(s1);
	while (is_charset(s1[fin - 1], set) == 1)
		fin--;
	while (is_charset(s1[deb], set) == 1 && deb < fin)
		deb++;
	str = malloc(fin - deb + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i + deb < fin)
	{
		str[i] = s1[i + deb];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int	main(int argc, char **argv)
{
	char	*str;
	char	*snd;

	(void)argc;
	str = ft_strtrim(argv[1], argv[2]);
	snd = strtrim(argv[1], argv[2]);
	printf("--> '%s' VS tripouille : %s\n", str, 
	((strcmp(str, "tripouille") == 0) ? "SAME" : "DIFFERENT"));
	printf("--> '%s' VS tripouille : %s\n", snd, 
	((strcmp(snd, "tripouille") == 0) ? "SAME" : "DIFFERENT"));
	free(str);
	free(snd);
	return (0);
}*/
