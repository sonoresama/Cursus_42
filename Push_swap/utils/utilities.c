/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:48:05 by eorer             #+#    #+#             */
/*   Updated: 2022/12/12 18:19:23 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pile	init_pile(char **arg, int size, t_long (*f)(const char *nptr))
{
	t_pile	pl;
	int		i;

	i = 0;
	pl.content = malloc(size * sizeof(int));
	if (arg)
	{
		while (pl.content && i < size)
		{
			pl.content[i] = f(arg[i]);
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

int	is_sorted(int *tab, int size)
{
	int	i;

	i = 1;
	while (tab && i < size)
	{
		if (tab[i] < tab[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_piles(t_pile a, t_pile b, int size)
{
	int	i;

	i = 0;
	ft_printf("a           b\n\n");
	while (i < size)
	{
		ft_printf("%i         %i\n", a.content[i], b.content[i]);
		i++;
	}
	ft_printf("\n");
}
