/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:30:40 by eorer             #+#    #+#             */
/*   Updated: 2022/12/09 14:41:20 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(pile a)
{
	int	tmp;

	if (a.size < 2)
		return ;
	tmp = a.content[0];
	a.content[0] = a.content[1];
	a.content[1] = tmp;
}

void	push(pile a, pile b)
{
	int	i;

	if (b.size == 0)
		return ;
	i = a.size;
	while (i > 0)
	{
		a.content[i] = a.content[i - 1];
		i--;
	}
	a.content[i] = b.content[i];
	while (i < b.size - 1)
	{
		b.content[i] = b.content[i + 1];
		i++;
	}
	b.content[i] = 0;
	a.size += 1;
	b.size -= 1;
}

void	rotate(pile a)
{
	int	tmp;
	int	i;

	tmp = a.content[0];
	i = 0;
	while (i < a.size - 1)
	{
		a.content[i] = a.content[i + 1];
		i++;
	}
	a.content[i] = tmp;
}

void	reverse_rotate(pile a)
{
	int	tmp;
	int	i;

	i = a.size - 1;
	tmp = a.content[i];
	while (i > 0)
	{
		a.content[i] = a.content[i - 1];
		i--;
	}
	a.content[i] = tmp;
}
