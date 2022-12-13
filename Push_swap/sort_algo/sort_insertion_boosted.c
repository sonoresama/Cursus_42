/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion_boosted.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:53:06 by eorer             #+#    #+#             */
/*   Updated: 2022/12/13 18:02:03 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define NB_BLOCKS 5

int	*indexes_blocks(int div, t_pile *a)
{
	int	*tab;
	int		i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * NB_BLOCKS);
	if (!tab)
		return (0);
	while (i < NB_BLOCKS)
	{
		tab[i] = i * div;
		i++;
	}
	return (tab);
}

void	init_blocks(t_pile *a, t_pile *b, int **srt_tab, int **i_blocks)
{
	int	*tab;
	int	*blocks;
	int	div;

	tab = sorted_tab(a, b);
	if (!tab)
		return ;
	div = a->size / NB_BLOCKS;
	blocks = indexes_blocks(div); 
	if (!blocks)
		return ;
	*srt_tab = tab;
	*i_blocks = blocks;
}

int	is_in_block(int nb, int *i_block, int *str_tab, int block)
{
	int	i;

	i = str_tab[i_block[block]];
	while (i < str_tab[i_block[block + 1]])
	{
		if (str_tab[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

void	insertion_boosted(t_pile *a, t_pile *b)
{
	int	*str_tab;
	int	*i_blocks;
	int	block;
	int	i;

	init_blocks(a, b, &str_tab, &i_blocks);
	if (!str_tab || !i_blocks)
		return ;
	while (!is_sorted(a->content))
	{
		block = 0;
		while (block < NB_BLOCKS)
		{
			i = 0;
			while ()
			i++;
		}
	}
}

