/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:54:38 by eorer             #+#    #+#             */
/*   Updated: 2022/12/09 16:04:07 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

pile	init_pile(char **arg, int size, int (*f)(const char *nptr))
{
	int	i;
	pile	pl;

	i = 0;
	pl.content = malloc(size * sizeof(int));
	if (arg)
	{
		while (pl.content && i < size)
		{
			pl.content[i] = f(arg[i + 1]);
			i++;
		}
		pl.size = size;
	}
	else
	{
		while (pl.content && i < size)
		{
			pl.content[i] = 0;
			i++;
		}
		pl.size = 0;
	}
	return (pl);
}

void	print_piles(pile a, pile b, int size)
{
	int	i;

	i = 0;
	ft_printf("a           b\n\n");
	while (i < size)
	{
		printf("%02i         %02i\n", a.content[i], b.content[i]);
		i++;
	}
	ft_printf("\n");
}

/*int	main(int argc, char **argv)
{
	pile	a;
	pile	b;

	a = init_pile(argv, argc - 1, &ft_atoi);
	if (!a.content)
		return (0);
	b = init_pile(NULL, argc - 1, &ft_atoi);
	if (!b.content)
		return (0);
	print_piles(a, b, argc - 1);
	reverse_rotate(a);
	reverse_rotate(a);
	print_piles(a, b, argc - 1);
	free (a.content);
	free (b.content);
	return (0);
}*/
