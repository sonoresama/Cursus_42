/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:52:12 by eorer             #+#    #+#             */
/*   Updated: 2022/11/08 17:03:04 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	f_test(unsigned int nb, char *add)
{
	if (nb % 2 == 0)
		*add = (char)ft_toupper(*add);
	else
		*add = (char)ft_tolower(*add);
}

int	main(int argc, char **argv)
{
	char	*str;
	void	(*f)(unsigned int, char *);

	(void)argc;
	f = &f_test;
	str = argv[1];
	ft_striteri(str, f);
	printf("-->> %s\n", str);
	return (0);
}*/
