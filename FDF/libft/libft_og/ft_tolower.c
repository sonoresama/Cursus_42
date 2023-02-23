/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:46:52 by eorer             #+#    #+#             */
/*   Updated: 2022/11/07 17:51:30 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("--> %c\n", ft_tolower(argv[1][0]));
	printf("--> %c", tolower(argv[1][0]));
	return (0);
}*/
