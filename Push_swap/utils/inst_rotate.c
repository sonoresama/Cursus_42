/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:10:39 by eorer             #+#    #+#             */
/*   Updated: 2022/12/12 15:17:03 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_pile *a, t_pile *b, int main)
{
	int	tmp;
	int	i;

	(void)b;
	tmp = a->content[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->content[i] = a->content[i + 1];
		i++;
	}
	a->content[i] = tmp;
	if (!main)
		ft_printf("ra\n");
}

void	rotate_b(t_pile *a, t_pile *b, int main)
{
	int	tmp;
	int	i;

	(void)a;
	tmp = b->content[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->content[i] = b->content[i + 1];
		i++;
	}
	b->content[i] = tmp;
	if (!main)
		ft_printf("rb\n");
}

void	rotate_rr(t_pile *a, t_pile *b)
{
	int	main;

	main = 1;
	rotate_a(a, b, main);
	rotate_b(a, b, main);
	ft_printf("rr\n");
}
