/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:37:26 by eorer             #+#    #+#             */
/*   Updated: 2022/11/19 15:20:06 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	char	*str;

	str = NULL;
//	str = "Hello tito comment ca va coco bello. Il etait une fois une fpurmi verte qui courrait dans la street";
	/*a = ft_printf(" NULL %s NULL", NULL);
	printf("Taille : %d\n", a);
	b = printf(" NULL %s NULL", NULL);
	printf("Taille : %d\n", b);*/
	a = ft_printf("  NULL %s NULL\n", str);
	printf("taille : %d\n", a);
	b = printf("  NULL %s NULL\n", str);
	printf("taille : %d\n", b);
	return (0);
}
