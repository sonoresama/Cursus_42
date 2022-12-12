/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:11:22 by eorer             #+#    #+#             */
/*   Updated: 2022/12/12 15:17:12 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_pile *a, t_pile *b, int main)
{
	int	tmp;

	(void)b;
	if (a->size < 2)
		return ;
	tmp = a->content[0];
	a->content[0] = a->content[1];
	a->content[1] = tmp;
	if (!main)
		ft_printf("sa\n");
}

void	swap_b(t_pile *a, t_pile *b, int main)
{
	int	tmp;

	(void)a;
	if (b->size < 2)
		return ;
	tmp = b->content[0];
	b->content[0] = b->content[1];
	b->content[1] = tmp;
	if (!main)
		ft_printf("sb\n");
}

void	swap_ss(t_pile *a, t_pile *b)
{
	int	main;

	main = 1;
	swap_a(a, b, main);
	swap_b(a, b, main);
	ft_printf("ss\n");
}
