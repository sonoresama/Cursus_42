/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:11:06 by eorer             #+#    #+#             */
/*   Updated: 2022/12/12 15:16:24 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_pile *a, t_pile *b)
{
	int	i;

	if (b->size == 0)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->content[i] = a->content[i - 1];
		i--;
	}
	a->content[i] = b->content[i];
	while (i < b->size - 1)
	{
		b->content[i] = b->content[i + 1];
		i++;
	}
	b->content[i] = 0;
	a->size += 1;
	b->size -= 1;
	ft_printf("pa\n");
}

void	push_b(t_pile *a, t_pile *b)
{
	int	i;

	if (a->size == 0)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->content[i] = b->content[i - 1];
		i--;
	}
	b->content[i] = a->content[i];
	while (i < a->size - 1)
	{
		a->content[i] = a->content[i + 1];
		i++;
	}
	a->content[i] = 0;
	b->size += 1;
	a->size -= 1;
	ft_printf("pb\n");
}
