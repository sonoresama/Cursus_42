/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:10:18 by eorer             #+#    #+#             */
/*   Updated: 2022/12/12 15:22:51 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_pile *a, t_pile *b, int main)
{
	int	tmp;
	int	i;

	(void)b;
	i = a->size - 1;
	tmp = a->content[i];
	while (i > 0)
	{
		a->content[i] = a->content[i - 1];
		i--;
	}
	a->content[i] = tmp;
	if (!main)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_pile *a, t_pile *b, int main)
{
	int	tmp;
	int	i;

	(void)a;
	i = b->size - 1;
	tmp = b->content[i];
	while (i > 0)
	{
		b->content[i] = b->content[i - 1];
		i--;
	}
	b->content[i] = tmp;
	if (!main)
		ft_printf("rrb\n");
}

void	reverse_rotate_rrr(t_pile *a, t_pile *b)
{
	int	main;

	main = 1;
	reverse_rotate_a(a, b, main);
	reverse_rotate_b(a, b, main);
	ft_printf("rrr\n");
}
