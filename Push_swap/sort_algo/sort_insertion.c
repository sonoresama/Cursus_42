/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:49:36 by eorer             #+#    #+#             */
/*   Updated: 2022/12/12 15:17:36 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static	int	index_smaller(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (tab && i < size)
	{
		if (tab[i] < tab[tmp])
			tmp = i;
		i++;
	}
	return (tmp);
}

void	insertion_sort(t_pile *a, t_pile *b)
{
	int	i;
	int	small;

	while (!is_sorted(a->content, a->size) && a->size > 3)
	{
		i = 0;
		small = index_smaller(a->content, a->size);
		if (small <= a->size / 2)
		{
			while (i++ < small)
				rotate_a(a, b, 0);
		}
		else
		{
			while (small + i++ != a->size)
				reverse_rotate_a(a, b, 0);
		}
		push_b(a, b);
	}
	if (a->size <= 3)
		three_digit_sort(a, b);
	while (b->size != 0)
		push_a(a, b);
}
