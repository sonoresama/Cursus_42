/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:30:18 by eorer             #+#    #+#             */
/*   Updated: 2022/11/11 15:15:16 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*char	ft_test(unsigned int nb, char c)
{
	char	a;

	if (nb % 2 == 0)
		a = (char)ft_toupper(c);
	else
		a = (char)ft_tolower(c);
	return (a);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc (ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (i < ft_strlen(s))
	{
		str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int	main(int argc, char **argv)
{
	char	*str;
	char	(*f)(unsigned int, char);

	(void)argc;
	f = &ft_test;
	str = ft_strmapi(argv[1], f);
	printf("--> %s\n", str);
	free(str);
	return (0);
}*/
