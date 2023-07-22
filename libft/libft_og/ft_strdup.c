/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:33:05 by eorer             #+#    #+#             */
/*   Updated: 2022/11/11 11:08:34 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

char	*ft_strdup(const char *src)
{
	void	*dest;

	if (!src)
		return (NULL);
	dest = malloc(ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	dest = (char *)ft_memcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}

/*int	main(void)
{
	char	*ptr;
	char	s[] = "coucou";

	ptr = ft_strdup(s);
	printf("--> %s\n", ptr);
	free(ptr);
	return (0);
}*/
