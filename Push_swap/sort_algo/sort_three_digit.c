/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:28:55 by eorer             #+#    #+#             */
/*   Updated: 2022/12/15 15:39:03 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	only_three(t_pile *a, t_pile *b)
{
	if (is_sorted(a->content, a->size))
		return ;
	else if (a->size == 2)
		swap_a(a, b, 0);
	else if (a->content[1] >= a->content[0] && a->content[2] < a->content[1])
	{
		if (a->content[0] < a->content[2])
		{
			reverse_rotate_a(a, b, 0);
			swap_a(a, b, 0);
		}
		else
			reverse_rotate_a(a, b, 0);
	}
	else if (a->content[1] < a->content[0] && a->content[2] < a->content[1])
	{
		swap_a(a, b, 0);
		reverse_rotate_a(a, b, 0);
	}
	else if (a->content[1] < a->content[0] && a->content[0] > a->content[2])
		rotate_a(a, b, 0);
	else if (a->content[1] < a->content[0] && a->content[0] <= a->content[2])
		swap_a(a, b, 0);
}

void	three_digit_sort(t_pile *a, t_pile *b)
{
	if (a->size <= 3)
	{
		only_three(a, b);
		return ;
	}
	if (a->content[0] < a->content [1] && a->content[1] < a->content[2])
		return ;
	if (a->content[0] > a->content[1] && a->content[1] > a->content[2])
		swap_a(a, b, 0);
	if (a->content[0] < a->content[1] && a->content[0] > a->content[2])
	{
		rotate_a(a, b, 0);
		swap_a(a, b, 0);
		reverse_rotate_a(a, b, 0);
	}
	if (a->content[0] > a->content[1] && a->content[1] < a->content[2])
		swap_a(a, b, 0);
	if (a->content[0] < a->content[1] && a->content[0] < a->content[2])
	{
		if (a->content[0] < a->content [1] && a->content[1] < a->content[2])
			return ;
		rotate_a(a, b, 0);
		swap_a(a, b, 0);
		reverse_rotate_a(a, b, 0);
	}
}
