/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:37:06 by eorer             #+#    #+#             */
/*   Updated: 2022/12/20 12:31:09 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	partition(t_pile *a, t_pile *b, int size)
{
	int	push;
	int	i;
	int	pivot;
	int	*srt_lst;

	srt_lst = sorted_tab(a, size);
	pivot = srt_lst[size / 2];
	i = 0;
	push = 0;
	while (i < size)
	{
		if (a->content[0] < pivot)
		{
			push_b(a, b);
			push++;
		}
		else
			rotate_a(a, b, 0);
		i++;
	}
	free(srt_lst);
	return (push);
}

int	partition_bis(t_pile *a, t_pile *b, int size)
{
	int	push;
	int	i;
	int	pivot;
	int	*srt_lst;

	srt_lst = sorted_tab(a, size);
	pivot = srt_lst[size / 2];
	i = 0;
	push = 0;
	while (i < size)
	{
		if (a->content[0] < pivot)
		{
			push_b(a, b);
			push++;
		}
		else
			rotate_a(a, b, 0);
		i++;
	}
	i = -1;
	while (i++ < size - push - 1)
		reverse_rotate_a(a, b, 0);
	free(srt_lst);
	return (push);
}

void	recursive_bis(t_pile *a, t_pile *b, int size)
{
	int	push;
	int	i;

	i = -1;
	if (size <= 3)
	{
		three_digit_sort(a, b);
		return ;
	}
	push = partition_bis(a, b, size);
	recursive_bis(a, b, size - push);
	if (push <= 3)
	{
		while (i++ < push - 1)
			push_a(a, b);
		three_digit_sort(a, b);
		recursive_bis(a, b, push);
	}
	else
	{
		while (i++ < push - 1)
			push_a(a, b);
		recursive_bis(a, b, push);
	}
}

void	recursive(t_pile *a, t_pile *b, int size)
{
	int	push;
	int	i;

	i = -1;
	if (size <= 3)
	{
		three_digit_sort(a, b);
		return ;
	}
	push = partition(a, b, size);
	recursive(a, b, size - push);
	if (push <= 3)
	{
		while (i++ < push - 1)
			push_a(a, b);
		three_digit_sort(a, b);
		recursive_bis(a, b, push);
	}
	else
	{
		while (i++ < push - 1)
			push_a(a, b);
		recursive_bis(a, b, push);
	}
}

void	sort_quick(t_pile *a, t_pile *b, int size)
{
	if (is_sorted(a->content, size))
		return ;
	recursive(a, b, a->size);
}
