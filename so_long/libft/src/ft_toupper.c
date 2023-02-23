/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:27:39 by eorer             #+#    #+#             */
/*   Updated: 2022/11/07 17:47:59 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + 'A' - 'a');
	return (c);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("--> %c\n", ft_toupper(argv[1][0]));
	printf("--> %c", toupper(argv[1][0]));
	return (0);
}*/
