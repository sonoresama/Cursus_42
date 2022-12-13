/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:54:38 by eorer             #+#    #+#             */
/*   Updated: 2022/12/13 18:02:50 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	check_doublon(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab && i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] == tab[i])
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_args(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!ft_atoi(tab[i]))
		{
			if (!ft_isdigit(tab[i][0]) || ft_strlen(tab[i]) > 1)
				return (0);
		}
		else
		{
			if (ft_atoi(tab[i]) > INT_MAX || ft_atoi(tab[i]) < INT_MIN)
				return (0);
		}
		i++;
	}
	return (1);
}

static int	overall_check(char **argv, int argc, int *size, char ***tab)
{
	if (argc == 2)
	{
		*tab = ft_split(argv[1], ' ');
		*size = ft_size_tab(argv[1], ' ');
	}
	else
	{
		*tab = argv + 1;
		*size = argc - 1;
	}
	if (!check_args(*tab, *size))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_pile	a;
	t_pile	b;
	char	**tab;
	int		size;

	if (!overall_check(argv, argc, &size, &tab))
		return (0);
	a = init_pile(tab, size, &ft_atoi);
	if (!a.content)
		return (0);
	b = init_pile(NULL, size, &ft_atoi);
	if (!b.content)
		return (0);
	if (!check_doublon(a.content, a.size))
		return (0);
	insertion_sort(&a, &b);
	free (a.content);
	free (b.content);
	if (argc == 2)
	{
		free_tab(tab);
		free(tab);
	}
	return (0);
}
