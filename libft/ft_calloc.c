/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:21:50 by eorer             #+#    #+#             */
/*   Updated: 2022/11/10 17:25:04 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <stddef.h>
#include <stdint.h>*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	a;

	a = nmemb * size;
	if (a / size != nmemb)
		return (0);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*int main(void)
{
	void	*p = ft_calloc(SIZE_MAX, SIZE_MAX);

	printf("--> %s\n", (p == NULL) ? "NULL" : "KO");
	free(p);
	return (0);
}*/
