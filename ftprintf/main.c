/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:37:26 by eorer             #+#    #+#             */
/*   Updated: 2022/11/21 10:48:34 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = printf("Hexa de 42440: %X\n", 42440); 
	ft_printf("  Taille : %i\n", a);
	b = ft_printf("Ft Hexa de 42440: %X\n", 42440); 
	ft_printf("  Taille : %i\n", b);
	printf("Hexa de -42440 : %X\n", -42440); 
	ft_printf("Ft Hexa de -42440 : %X\n", -42440); 
	return (0);
}
